package com.handControlUI.edu;

import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JFrame;

/**
 * 拇指会议登录页面UI
 * @author storm
 *
 */
public class LoginUI {
	//登录页面窗口
	private JFrame jf;
	//采用流式布局
	private FlowLayout fl;
	//登录按钮
	private JButton login;
	//注册按钮
	private JButton register;
	/*
	 * 初始化登录界面
	 */
	public LoginUI() {
		//建立一个窗口
		jf = new JFrame("拇指会议");
		//使用流布局
		fl = new FlowLayout();
		//修改窗口布局
		jf.setLayout(fl);
		//创建按钮
		login = new JButton("登录");
		register = new JButton("注册");
		//添加按钮
		jf.add(login);
		jf.add(register);
		//设置窗口大小
		jf.setSize(800,1000);
		//设置窗口初始位置
		jf.setLocation(600,500);
		//设置窗口关闭方式
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	/*
	 * 打开窗口
	 */
	public void open() {
		jf.setVisible(true);
	}
	/*
	 * 关闭窗口
	 */
	public void close() {
		jf.setVisible(false);
	}
}
