#include <jni.h>
#include <string>

extern "C" {
extern int executePatch(int argc, char *argv[]);
extern int executeDiff(int argc, char *argv[]);
}

/*
 * TODO  组装新包
 */
extern "C"
JNIEXPORT jint JNICALL
Java_com_leon_bsdiffupdatedemo_BsPatchUtils_patch(JNIEnv *env, jclass clazz, jstring old_apk,
                                                  jstring new_apk, jstring patch_file) {
    // TODO: implement patch()
    int args = 4;
    char *argv[args];
    argv[0] = "DiffUtils";

    argv[1] = (char *) (env->GetStringUTFChars(old_apk, 0));
    argv[2] = (char *) (env->GetStringUTFChars(new_apk, 0));
    argv[3] = (char *) (env->GetStringUTFChars(patch_file, 0));

    //此处executePathch()就是上面我们修改出的
    int result = executePatch(args, argv);

    env->ReleaseStringUTFChars(old_apk, argv[1]);
    env->ReleaseStringUTFChars(new_apk, argv[2]);
    env->ReleaseStringUTFChars(patch_file, argv[3]);
    return result;
}


/*
 * TODO  差分包获取
 */
extern "C"
JNIEXPORT jint JNICALL
Java_com_leon_bsdiffupdatedemo_BsPatchUtils_diff(JNIEnv *env, jclass clazz, jstring old_apk,
                                                 jstring new_apk, jstring diss_file) {
    // TODO: implement diff()

    int args = 4;
    char *argv[args];
    argv[0] = "DiffUtils";

    argv[1] = (char *) (env->GetStringUTFChars(old_apk, 0));
    argv[2] = (char *) (env->GetStringUTFChars(new_apk, 0));
    argv[3] = (char *) (env->GetStringUTFChars(diss_file, 0));

    //这里是真正执行差分包的地方
    int result = executeDiff(args, argv);

    env->ReleaseStringUTFChars(old_apk, argv[1]);
    env->ReleaseStringUTFChars(new_apk, argv[2]);
    env->ReleaseStringUTFChars(diss_file, argv[3]);
    return result;
}