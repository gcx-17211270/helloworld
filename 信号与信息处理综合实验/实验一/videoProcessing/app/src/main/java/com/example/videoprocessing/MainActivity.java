package com.example.videoprocessing;

import android.content.Context;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioRecord;
import android.media.AudioTrack;
import android.media.MediaPlayer;
import android.media.MediaRecorder;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.SurfaceView;
import android.view.View;
import android.widget.Button;
import android.widget.ScrollView;
import android.widget.TextView;
import android.widget.ZoomControls;

import androidx.appcompat.app.AppCompatActivity;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.ShortBuffer;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    public static final String TAG = "PCMSample";

    //是否在录制
    private boolean isRecording = false;
    //开始录音
    private Button startAudio;
    //结束录音
    private Button stopAudio;
    //播放录音
    private Button playAudio;
    //播放处理后文件
    private Button playAudio2;
    //删除文件
    private Button deleteAudio;
    //分析文件
    private Button analysisAudio;

    static  int frequency = 16000;//分辨率
    static final int yMax = 50;//Y轴缩小比例最大值
    static final int yMin = 1;//Y轴缩小比例最小值

    AudioProcess audioProcess = new AudioProcess();
    SurfaceView sfv;  //绘图所用

    private ScrollView mScrollView;
    private TextView tv_audio_succeess;

    //pcm文件
    private File file;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        initView();
    }

    //初始化View
    private void initView() {

        mScrollView = (ScrollView) findViewById(R.id.mScrollView);
        tv_audio_succeess = (TextView) findViewById(R.id.tv_audio_succeess);
        printLog("初始化成功");
        startAudio = (Button) findViewById(R.id.startAudio);
        startAudio.setOnClickListener(this);
        stopAudio = (Button) findViewById(R.id.stopAudio);
        stopAudio.setOnClickListener(this);
        playAudio = (Button) findViewById(R.id.playAudio);
        playAudio.setOnClickListener(this);
        playAudio2 = (Button) findViewById(R.id.playAudio2);
        playAudio2.setOnClickListener(this);
        deleteAudio = (Button) findViewById(R.id.deleteAudio);
        deleteAudio.setOnClickListener(this);
        analysisAudio = (Button) findViewById(R.id.analysisAudio);
        analysisAudio.setOnClickListener(this);

        //画笔和画板
        sfv = (SurfaceView)this.findViewById(R.id.surfaceView);
        //初始化显示
        Context mContext = getApplicationContext();
        audioProcess.initDraw(yMax * 1, sfv.getHeight(),mContext,frequency);
    }

    //点击事件
    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.startAudio:
                Thread thread = new Thread(new Runnable() {
                    @Override
                    public void run() {
                        StartRecord();
                        Log.e(TAG,"start");
                    }
                });
                thread.start();
                printLog("开始录音");
                ButtonEnabled(false, true, false, false, true);
                break;
            case R.id.stopAudio:
                isRecording = false;
                ButtonEnabled(true, false, true, false, true);
                printLog("停止录音");
                break;
            case R.id.playAudio:
                PlayRecord();
                ButtonEnabled(true, false, true, true, true);
                printLog("播放录音");
                break;
            case R.id.playAudio2:
                PlayRecord2();
                ButtonEnabled(true, false, true, true, true);
                printLog("播放处理后文件");
                break;
            case R.id.deleteAudio:
                deleFile();
                ButtonEnabled(true, false, false, false, false);
                break;
            case R.id.analysisAudio:
                printLog("录音文件分析");
                try {
                    AnalysisRecord();
                    ButtonEnabled(true, false, true, true, true);
                } catch (IOException e) {
                    Log.e(TAG,"分析失败");
                    e.printStackTrace();
                }
                break;
        }
    }

    //打印log
    private void printLog(final String resultString) {
        tv_audio_succeess.post(new Runnable() {
            @Override
            public void run() {
                tv_audio_succeess.append(resultString + "\n");
                mScrollView.fullScroll(ScrollView.FOCUS_DOWN);
            }
        });
    }

    //获取/失去焦点
    private void ButtonEnabled(boolean start, boolean stop, boolean play, boolean play2, boolean analysis) {
        startAudio.setEnabled(start);
        stopAudio.setEnabled(stop);
        playAudio.setEnabled(play);
        playAudio2.setEnabled(play2);
        analysisAudio.setEnabled(analysis);
    }

    //开始录音
    private void StartRecord() {
        Log.i(TAG,"开始录音");
        //16K采集率
        //int frequency = 16000;
        //格式
        int channelConfiguration = AudioFormat.CHANNEL_CONFIGURATION_MONO;
        //8Bit
        int audioEncoding = AudioFormat.ENCODING_PCM_16BIT;
        //生成PCM文件
        file = new File(Environment.getExternalStorageDirectory()
                .getAbsolutePath()+ "/videoProcessing.pcm");
        Log.i(TAG,"生成文件");
        //如果存在，就先删除再创建
        if (file.exists())
            file.delete();
        Log.i(TAG,"删除文件");
        try {
            file.createNewFile();
            Log.i(TAG,"创建文件");
        } catch (IOException e) {
            Log.i(TAG,"未能创建");
            throw new IllegalStateException("未能创建" + file.toString());
        }
        try {
            //输出流
            OutputStream os = new FileOutputStream(file);
            BufferedOutputStream bos = new BufferedOutputStream(os);
            DataOutputStream dos = new DataOutputStream(bos);
            int bufferSize = AudioRecord.getMinBufferSize(frequency, channelConfiguration, audioEncoding);
            AudioRecord audioRecord = new AudioRecord(MediaRecorder.AudioSource.MIC, frequency, channelConfiguration, audioEncoding, bufferSize);

            audioProcess.baseLine = sfv.getHeight()-100;
            audioProcess.frequence = frequency;
            audioProcess.start(audioRecord, bufferSize, sfv);

            short[] buffer = new short[bufferSize];
            audioRecord.startRecording();
            Log.i(TAG, "开始录音");
            isRecording = true;
            while (isRecording) {
                int bufferReadResult = audioRecord.read(buffer, 0, bufferSize);
                for (int i = 0; i < bufferReadResult; i++) {
                    dos.writeShort(buffer[i]);
                }
            }
            audioRecord.stop();
            audioProcess.stop(sfv);
            dos.close();
        } catch (Throwable t) {
            Log.e(TAG, "录音失败");
        }
    }

    //播放文件
    private void PlayRecord() {
        if(file == null){
            return;
        }
        //读取文件
        int musicLength = (int) (file.length() / 2);
        short[] music = new short[musicLength];
        try {
            InputStream is = new FileInputStream(file);
            BufferedInputStream bis = new BufferedInputStream(is);
            DataInputStream dis = new DataInputStream(bis);
            int i = 0;
            while (dis.available() > 0) {
                music[i] = dis.readShort();
                i++;
            }
            dis.close();
            AudioTrack audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC,
                    frequency, AudioFormat.CHANNEL_CONFIGURATION_MONO,
                    AudioFormat.ENCODING_PCM_16BIT,
                    musicLength * 2,
                    AudioTrack.MODE_STREAM);
            audioTrack.play();
            audioTrack.write(music, 0, musicLength);
            audioTrack.stop();
        } catch (Throwable t) {
            Log.e(TAG, "播放失败");
        }
    }

    //播放文件
    private void PlayRecord2() {
        File file = new File(Environment.getExternalStorageDirectory()
                .getPath()+"/videoAfterProcessing.pcm");
        if(file == null){
            return;
        }
        //读取文件
        int musicLength = (int) (file.length() / 2);
        short[] music = new short[musicLength];
        try {
            InputStream is = new FileInputStream(file);
            BufferedInputStream bis = new BufferedInputStream(is);
            DataInputStream dis = new DataInputStream(bis);
            int i = 0;
            while (dis.available() > 0) {
                music[i] = dis.readShort();
                i++;
            }
            dis.close();
            AudioTrack audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC,
                    frequency, AudioFormat.CHANNEL_CONFIGURATION_MONO,
                    AudioFormat.ENCODING_PCM_16BIT,
                    musicLength * 2,
                    AudioTrack.MODE_STREAM);
            audioTrack.play();
            audioTrack.write(music, 0, musicLength);
            audioTrack.stop();
        } catch (Throwable t) {
            Log.e(TAG, "播放失败");
        }
    }

    //删除文件
    private void deleFile() {
        String basePath = Environment.getExternalStorageDirectory().getPath();
        //wav文件目录
        String outFileName = basePath+"/videoProcessing.wav";
        File newfile = new File(outFileName);
        String outFileName2 = basePath+"/videoAfterProcessing.pcm";
        File newfile2 = new File(outFileName2);

        if(file == null){
            return;
        }
        file.delete();

        if(newfile == null){
            return;
        }
        newfile.delete();
        if(newfile2 == null){
            return;
        }
        newfile2.delete();
        printLog("文件删除成功");
    }

    private void AnalysisRecord() throws IOException {
        //bigtolittle(Environment.getExternalStorageDirectory()
        //        .getAbsolutePath()+ "/videoProcessing.pcm");
        PCMCovWavUtil pcnCovWav = new PCMCovWavUtil();
        pcnCovWav.convertWaveFile();
    }

    //8bit采样才能正常转换到wav，16bit就不行，有个说是大小端的问题，writeshort是大端要转化为小端，
    //转换函数是下面这段，调用在上面AnalysisRecord()第一行，可是还是有问题，不知道是怎么用
    //是因为8bit一次采样一个字节，大小端存储都一样，而16bit两个字节大小端就涉及存放顺序了？
    private String bigtolittle( String fileName) throws IOException {

        File file = new File(fileName);    //filename为pcm文件，请自行设置

        InputStream in = null;
        byte[] bytes = null;
        in = new FileInputStream(file);
        bytes = new byte[in.available()];//in.available()是得到文件的字节数
        int length=bytes.length;
        while (length!=1){
            long i=  in.read(bytes,0,bytes.length);
            if(i==-1){
                break;
            }
            length-=i;
        }

        int dataLength = bytes.length;
        int shortlength = dataLength / 2;
        ByteBuffer byteBuffer = ByteBuffer.wrap(bytes, 0, dataLength);
        ShortBuffer shortBuffer = byteBuffer.order(ByteOrder.LITTLE_ENDIAN).asShortBuffer();//此处设置大小端
        short[] shorts = new short[shortlength];
        shortBuffer.get(shorts, 0, shortlength);
        File file1 = File.createTempFile("pcm",null);//输出为临时文件
        String pcmtem = file1.getPath();
        FileOutputStream fos1 = new FileOutputStream(file1);
        BufferedOutputStream bos1 = new BufferedOutputStream(fos1);
        DataOutputStream dos1 = new DataOutputStream(bos1);
        for (int i = 0; i < shorts.length; i++) {
            dos1.writeShort(shorts[i]);
        }
        dos1.close();
        Log.d("gg", "bigtolittle: "+"="+shorts.length);
        return pcmtem;
    }

}
