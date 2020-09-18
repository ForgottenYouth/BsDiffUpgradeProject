/*
 * Copyright (C), 2015-2020, 物联云仓科技有限公司
 * FileName: BsPatchUtils
 * Author: shiwenliang
 * Date: 2020/9/4 13:45
 * Description: 合成包工具
 */
package com.leon.bsdiffupdatedemo;

public class BsPatchUtils {
    static{
        System.loadLibrary("DiffUtils");
    }

    public static native int patch(String oldApk,String newApk,String patchFile);

   public static native int diff(String oldApk ,String newApk,String dissFile);
}