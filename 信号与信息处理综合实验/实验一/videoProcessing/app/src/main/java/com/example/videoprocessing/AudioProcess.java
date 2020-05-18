package com.example.videoprocessing;

/**
 * 这个类是有三个功能，第一，采集数据；第二，进行快速傅里叶计算；第三，绘图。
 * 采集数据用AudioRecord类，网上讲解这个类的蛮多的，搞清楚构造类的各个参数就可以。
 * 绘图用的是SurfaceView Paint Canvas三个类
 * */

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.lang.Short;
import java.util.List;

import android.R.integer;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.DashPathEffect;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.PathEffect;
import android.graphics.Rect;
import android.graphics.Paint.Style;
import android.media.AudioRecord;
import android.os.Environment;
import android.util.Log;
import android.view.SurfaceView;
import android.widget.TextView;

public class AudioProcess {
	public static final float pi= (float) 3.1415926;
	//应该把处理前后处理后的谱线都显示出来
	private ArrayList<short[]> inBuf = new ArrayList<short[]>();//原始录入数据
	private ArrayList<int[]> outBuf = new ArrayList<int[]>();//处理后的数据
	private boolean isRecording = false;

	Context mContext;
	private int shift = 30;
	public int frequence = 0;

	private int length = 256;
	//y轴缩小的比例
	public int rateY = 21;
	//y轴基线
	public int baseLine = 0;
	//初始化画图的一些参数
	public void initDraw(int rateY, int baseLine,Context mContext, int frequence){
		this.mContext = mContext;
		this.rateY = rateY;
		this.baseLine = baseLine;
		this.frequence = frequence;
	}
	//启动程序
	public void start(AudioRecord audioRecord, int minBufferSize, SurfaceView sfvSurfaceView) {
		isRecording = true;
		new RecordThread(audioRecord, minBufferSize).start();
		//new ProcessThread().start();
		new DrawThread(sfvSurfaceView).start();
	}
	//停止程序
	public void stop(SurfaceView sfvSurfaceView){
		isRecording = false;
		inBuf.clear();
		//sfvSurfaceView;
		//drawBuf.clear();
		//outBuf.clear();
	}
	
	//录音线程
	class RecordThread extends Thread{
		private AudioRecord audioRecord;
		private int minBufferSize;
		
		public RecordThread(AudioRecord audioRecord,int minBufferSize){
			this.audioRecord = audioRecord;
			this.minBufferSize = minBufferSize;
		}
		
		public void run(){
			try{
				//输出流
//				File file = new File(Environment.getExternalStorageDirectory()
//						.getAbsolutePath() + "/videoProcessing.pcm");
//				OutputStream os = new FileOutputStream(file);
//				BufferedOutputStream bos = new BufferedOutputStream(os);
//				DataOutputStream dos = new DataOutputStream(bos);
				short[] buffer = new short[minBufferSize];
				audioRecord.startRecording();
				while(isRecording){
					int res = audioRecord.read(buffer, 0, minBufferSize);
//					for (int i = 0; i < res; i++) {
//						dos.writeShort(buffer[i]);
//					}
					synchronized (inBuf){
						inBuf.add(buffer);
					}
					//保证长度为2的幂次数
					length=up2int(res);
					//length = 256;
					short[]tmpBuf = new short[length];
					System.arraycopy(buffer, 0, tmpBuf, 0, length);
					
					Complex[]complexs = new Complex[length];
					int[]outInt = new int[length];
					for(int i=0;i < length; i++){
						Short short1 = tmpBuf[i];
						complexs[i] = new Complex(short1.doubleValue());
					}
					fft(complexs,length);
					for (int i = 0; i < length; i++) {
						outInt[i] = complexs[i].getIntValue();
					}
					synchronized (outBuf) {
						outBuf.add(outInt);
					}
				}
//				try {
//					fos.close();
//				} catch (Exception e) {
//					// TODO: handle exception
//					e.printStackTrace();
//				}
				audioRecord.stop();
			}catch (Exception e) {
				// TODO: handle exception
				Log.i("Rec E",e.toString());
			}
			
		}
	}

	//绘图线程
	class DrawThread extends Thread{
		//画板
		private SurfaceView sfvSurfaceView;
		//当前画图所在屏幕x轴的坐标
		//画笔
		private Paint mPaint;
		private Paint tPaint;
		private Paint dashPaint;
		public DrawThread(SurfaceView sfvSurfaceView) {
			this.sfvSurfaceView = sfvSurfaceView;
			//设置画笔属性
			mPaint = new Paint();
			mPaint.setColor(Color.BLUE);
			mPaint.setStrokeWidth(2);
			mPaint.setAntiAlias(true);
			
			tPaint = new Paint();
			tPaint.setColor(Color.YELLOW);
			tPaint.setStrokeWidth(1);
			tPaint.setAntiAlias(true);
			
			dashPaint = new Paint();
			dashPaint.setStyle(Paint.Style.STROKE);
			dashPaint.setColor(Color.GRAY);
			Path path = new Path();
	        path.moveTo(0, 10);
	        path.lineTo(480,10); 
	        PathEffect effects = new DashPathEffect(new float[]{5,5,5,5},1);
	        dashPaint.setPathEffect(effects);
		}
		
		@SuppressWarnings("unchecked")
		public void run() {
			while (isRecording) {
				ArrayList<int[]>buf = new ArrayList<int[]>();
				synchronized (outBuf) {
					if (outBuf.size() == 0) {
						continue;
					}
					buf = (ArrayList<int[]>)outBuf.clone();
					outBuf.clear();
				}
				//根据ArrayList中的short数组开始绘图
				for(int i = 0; i < buf.size(); i++){
					int[]tmpBuf = buf.get(i);
					SimpleDraw(tmpBuf, rateY, baseLine);
				}
				
			}
		}

		/**
		 * 绘制指定区域
		 *
		 * @param start
		 *            X 轴开始的位置(全屏)
		 * @param buffer
		 *             缓冲区
		 * @param rate
		 *            Y 轴数据缩小的比例
		 * @param baseLine
		 *            Y 轴基线
		 */

		private void SimpleDraw(int[] buffer, int rate, int baseLine){
			Canvas canvas = sfvSurfaceView.getHolder().lockCanvas(
					new Rect(0, 0, buffer.length,sfvSurfaceView.getHeight()));
			canvas.drawColor(Color.BLACK);
			canvas.drawText("幅度值", 0, 3, 2, 15, tPaint);
			canvas.drawText("原点(0,0)", 0, 7, 5, baseLine + 15, tPaint);
			canvas.drawText("频率(HZ)", 0, 6, sfvSurfaceView.getWidth() - 50, baseLine + 30, tPaint);
			canvas.drawLine(shift, 20, shift, baseLine, tPaint);
			canvas.drawLine(shift, baseLine, sfvSurfaceView.getWidth(), baseLine, tPaint);
			canvas.save();
			canvas.rotate(30, shift, 20);
			canvas.drawLine(shift, 20, shift, 30, tPaint);
			canvas.rotate(-60, shift, 20);
			canvas.drawLine(shift, 20, shift, 30, tPaint);
			canvas.rotate(30, shift, 20);
			canvas.rotate(30, sfvSurfaceView.getWidth()-1, baseLine);
			canvas.drawLine(sfvSurfaceView.getWidth() - 1, baseLine, sfvSurfaceView.getWidth() - 11, baseLine, tPaint);
			canvas.rotate(-60, sfvSurfaceView.getWidth()-1, baseLine);
			canvas.drawLine(sfvSurfaceView.getWidth() - 1, baseLine, sfvSurfaceView.getWidth() - 11, baseLine, tPaint);
			canvas.restore();
			//tPaint.setStyle(Style.STROKE);
			float index = sfvSurfaceView.getWidth() / 8;
			for(; index <= sfvSurfaceView.getWidth(); index = index + sfvSurfaceView.getWidth() / 8){
				canvas.drawLine(shift + index, baseLine, shift + index, 40, dashPaint);
				String str = String.valueOf(frequence * index / sfvSurfaceView.getWidth() / 2 );
				canvas.drawText( str, 0, str.length(), shift + index - 15, baseLine + 15, tPaint);
			}
			int y;
			for(int i = 0; i < buffer.length; i = i + 1){
				y = baseLine - buffer[i] / rateY ;
				canvas.drawLine(2*i + shift, baseLine, 2*i +shift, y, mPaint);
			}
			sfvSurfaceView.getHolder().unlockCanvasAndPost(canvas);
		}
	}

	/**
	 * 向上取最接近iint的2的幂次数.比如iint=320时,返回256
	 * @param iint
	 * @return
	 */
	private int up2int(int iint) {
		int ret = 1;
		while (ret<=iint) {
			ret = ret << 1;
		}
		return ret>>1;
	}
	
	//快速傅里叶变换
	public void fft(Complex[] xin,int N)
	{
	    int f,m,N2,nm,i,k,j,L;//L:运算级数
	    float p;
	    int e2,le,B,ip;
	    Complex w = new Complex();
	    Complex t = new Complex();
		N2 = N / 2;//每一级中蝶形的个数,同时也代表m位二进制数最高位的十进制权值
		f = N;//f是为了求流程的级数而设立的
		for(m = 1; (f = f / 2) != 1; m++);                             //得到流程图的共几级
	    nm = N - 2;
	    j = N2;
		/******倒序运算——雷德算法******/
		for(i = 1; i <= nm; i++)
		{
			if(i < j)//防止重复交换
	        {
	            t = xin[j];
	            xin[j] = xin[i];
	            xin[i] = t;
	        }
	        k = N2;
	        while(j >= k)
	        {
	            j = j - k;
	            k = k / 2;
	        }
	        j = j + k;
	    }
		/******蝶形图计算部分******/
		for(L=1; L<=m; L++)                                    //从第1级到第m级
		{
			e2 = (int) Math.pow(2, L);
			//e2=(int)2.pow(L);
			le=e2+1;
			B=e2/2;
			for(j=0;j<B;j++)                                    //j从0到2^(L-1)-1
			{
				p=2*pi/e2;
				w.real = Math.cos(p * j);
				//w.real=Math.cos((double)p*j);                                   //系数W
				w.image = Math.sin(p*j) * -1;
				//w.imag = -sin(p*j);
				for(i=j;i<N;i=i+e2)                                //计算具有相同系数的数据
				{
					ip=i+B;                                           //对应蝶形的数据间隔为2^(L-1)
	                t=xin[ip].cc(w);
	                xin[ip] = xin[i].cut(t);
	                xin[i] = xin[i].sum(t);
	            }
	        }
	    }
	}


	/**
	 * 绘制指定区域
	 *
	 * @param start
	 *            X 轴开始的位置(全屏)
	 * @param buffer
	 *             缓冲区
	 * @param rate
	 *            Y 轴数据缩小的比例
	 * @param baseLine
	 *            Y 轴基线
	 */
	public synchronized double[] IIRFilter(double[] signal, double[] a, double[] b) {

		double[] in = new double[b.length];
		double[] out = new double[a.length-1];

		double[] outData = new double[signal.length];

		for (int i = 0; i < signal.length; i++) {

			System.arraycopy(in, 0, in, 1, in.length - 1);
			in[0] = signal[i];

			//calculate y based on a and b coefficients
			//and in and out.
			float y = 0;
			for(int j = 0 ; j < b.length ; j++){
				y += b[j] * in[j];

			}

			for(int j = 0;j < a.length-1;j++){
				y -= a[j+1] * out[j];
			}

			//shift the out array
			System.arraycopy(out, 0, out, 1, out.length - 1);
			out[0] = y;

			outData[i] = y;


		}
		return outData;
	}

	/**
	 * 频域滤波
	 * @param originalPoints 原始数据
	 * @param samplingInterval 采样间隔, 单位是秒(s)
	 * @param lowpass 低通
	 * @return 滤波之后的数据
	 */
//	public static <SamplingPoint, FastFourierTransformer> List<SamplingPoint> lowpassFromFrequencyDomain(List<SamplingPoint> originalPoints, double samplingInterval, int lowpass){
//		int dataLen = originalPoints.size();
//		double[] signal = new double[dataLen];
//		for(int i = 0; i < originalPoints.size(); i++){
//			signal[i] = originalPoints.get(i).getRealY();
//		}
//
//		double Fs = 1.0 / samplingInterval;//采样频率
//		double frequencyResolution = Fs / dataLen;//频率分辨率
//
//		//进行傅里叶变换,使用的是commons-math包里面的快速傅里叶算法
//		FastFourierTransformer fft = new FastFourierTransformer(DftNormalization.STANDARD);
//		Complex[] complexArr = fft.transform(signal, TransformType.FORWARD);//正向傅里叶变换
//
//		//进行滤波,注意条件
//		if(lowpass < Fs / 2.0){
//			for(int i = 0; i < complexArr.length; i++){
//				//对称
//				if(i * frequencyResolution > lowpass && i * frequencyResolution < (Fs - lowpass)){
//					complexArr[i] = new Complex(0, 0);
//				}
//			}
//		}
//
//		//反傅里叶变换
//		Complex[] timeDomainArr = fft.transform(complexArr, TransformType.INVERSE);
//		List<SamplingPoint> points = new ArrayList<>();
//		for(int i = 0; i < timeDomainArr.length; i++){
//			//只用获取实部，不用获取虚部(虚部理论上应该是0),实部的数据就是时域曲线
//			SamplingPoint point = new SamplingPoint(i, (float) timeDomainArr[i].getReal());
//			points.add(point);
//		}
//		return points;
//	}

}
