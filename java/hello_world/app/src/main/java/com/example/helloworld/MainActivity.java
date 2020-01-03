package com.example.helloworld;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        //获取名字为tv_hello的TextView控件
        TextView show_hello= (TextView) findViewById(R.id.tv_hello);//其中R.id.tv_hello定义在src/main/res/layout/activity_main.xml
        //给TextView控件设置文字内容
        show_hello.setText("今天天气真冷啊，哈哈哈哈");
        //给TextView控件设置文字颜色
        show_hello.setTextColor(Color.RED);
        //给TextView控件设置文字大小
        show_hello.setTextSize(30);
    }
}
