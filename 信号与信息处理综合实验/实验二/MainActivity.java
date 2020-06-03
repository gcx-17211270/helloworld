package com.example.myapp;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.text.Html;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;

import org.opencv.android.OpenCVLoader;
import org.opencv.android.Utils;
import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.Point;
import org.opencv.core.Size;
import org.opencv.imgproc.Imgproc;

import java.io.InputStream;

import static android.widget.Toast.makeText;

public class MainActivity extends AppCompatActivity {
    private double max_size = 1024;
    private int PICK_IMAGE_REQUEST = 1;
    private ImageView myImageView;
    private Bitmap selectbp;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        staticLoadCVLibraries();

        myImageView = (ImageView)findViewById(R.id.imageView);
        myImageView.setScaleType(ImageView.ScaleType.FIT_CENTER);

        Button selectImageBtn = (Button)findViewById(R.id.select_btn);
        selectImageBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                makeText(MainActivity.this.getApplicationContext(), "start to browser image",
                        Toast.LENGTH_SHORT).show();
                selectImage();
            }
        });

        Button processBtn = (Button)findViewById(R.id.process_btn);
        processBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                makeText(MainActivity.this.getApplicationContext(), "hello, image process",
                        Toast.LENGTH_SHORT).show();
                //convertGray();
                filteringImg();
            }
        });
    }

    private void staticLoadCVLibraries(){
        boolean load = OpenCVLoader.initDebug();
        if(load) {
            Log.i("CV", "Open CV Libraries loaded...");
        }
        else{
            Toast.makeText(this.getApplicationContext(),"WARNING:Could not load OpenCV Libraries!",
                    Toast.LENGTH_LONG).show();
        }
    }

    private void convertGray() {
        Mat src = new Mat();
        Mat temp = new Mat();
        Mat dst = new Mat();
        Utils.bitmapToMat(selectbp, src);
        Imgproc.cvtColor(src, temp, Imgproc.COLOR_BGRA2BGR);
        Log.i("CV", "image type:" + (temp.type() == CvType.CV_8UC3));
        Imgproc.cvtColor(temp, dst, Imgproc.COLOR_BGR2GRAY);
        Utils.matToBitmap(dst, selectbp);
        myImageView.setImageBitmap(selectbp);
        //少了对src、temp、dst的release？;
    }

    //各种滤波函数
    private void filteringImg(){
        Mat src = new Mat();
        Mat dst = new Mat();

        Utils.bitmapToMat(selectbp, src);

        if (src.empty()){
            Log.e("Error", "Load bitmap failed.");
            return;
        }

        //均值滤波
        //Imgproc.blur(src, dst, new Size(5,5), new Point(-1,-1), Core.BORDER_DEFAULT);
        //高斯滤波
        //Imgproc.GaussianBlur(src, dst, new Size(0,0), 5, 0,
                //Core.BORDER_DEFAULT);
        //中值滤波
        //Imgproc.medianBlur(src, dst, 5);
        //最大最小值滤波（膨胀与腐蚀）
        Mat kernel = Imgproc.getStructuringElement(Imgproc.MORPH_RECT, new Size(3,3));
        Imgproc.dilate(src, dst, kernel);       //最大值滤波
        //Imgproc.erode(src, dst, kernel);        //最小值滤波

        //高斯双边滤波(程序崩溃了)
        //Imgproc.bilateralFilter(src, dst, 0 , 150, 15);

        //均值迁移滤波(程序崩溃了)
        //Imgproc.pyrMeanShiftFiltering(src, dst, 10, 50);

        Log.i("Success", "blur is ok.");

        Utils.matToBitmap(dst, selectbp);
        myImageView.setImageBitmap(selectbp);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode == PICK_IMAGE_REQUEST && resultCode == RESULT_OK && data != null && data.getData() != null) {
            Uri uri = data.getData();
            try {
                Log.d("image-tag", "start to decode selected image now...");
                InputStream input = getContentResolver().openInputStream(uri);
                BitmapFactory.Options options = new BitmapFactory.Options();
                options.inJustDecodeBounds = true;
                BitmapFactory.decodeStream(input, null, options);
                int raw_width = options.outWidth;
                int raw_height = options.outHeight;
                int max = Math.max(raw_width, raw_height);
                int newWidth = raw_width;
                int newHeight = raw_height;
                int inSampleSize = 1;
                if(max > max_size) {
                    newWidth = raw_width / 2;
                    newHeight = raw_height / 2;
                    while((newWidth/inSampleSize) > max_size || (newHeight/inSampleSize) > max_size) {
                        inSampleSize *=2;
                    }
                }
                options.inSampleSize = inSampleSize;
                options.inJustDecodeBounds = false;
                options.inPreferredConfig = Bitmap.Config.ARGB_8888;
                selectbp = BitmapFactory.decodeStream(getContentResolver().openInputStream(uri), null, options);

                myImageView.setImageBitmap(selectbp);

            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    private void selectImage() {
        Intent intent = new Intent();
        intent.setType("image/*");
        intent.setAction(Intent.ACTION_GET_CONTENT);
        startActivityForResult(Intent.createChooser(intent,"选择图像..."), PICK_IMAGE_REQUEST);
    }

}



