package com.handControlUI.edu;
/**
 * 拇指会议主类
 * @author storm
 *
 */
public class HandControl {
	private static LoginUI loginUI = new LoginUI();
	/*
	 * 会议程序入口
	 */
	public static void main(String[]args) {
		//打开登录界面
		loginUI.open();
	}
}
