#include "mainwindow.h"
#include <QApplication>
QString getDeviceImei()
{
    QAndroidJniEnvironment env;
       jclass contextClass = env->FindClass("android/content/Context");
       if(contextClass){
           qDebug() << "OLLEG: 1 found";
       }
       else{
           qDebug() << "OLLEG: 1 NOT found";
       }

       jfieldID fieldId = env->GetStaticFieldID(contextClass, "TELEPHONY_SERVICE", "Ljava/lang/String;");
       if(fieldId){
           qDebug() << "OLLEG: 2 found";
       }
       else{
           qDebug() << "OLLEG: 2 NOT found";
       }


       jstring telephonyManagerType = (jstring) env->GetStaticObjectField(contextClass, fieldId);
       if(telephonyManagerType){
           qDebug() << "OLLEG: 3 found";
       }
       else{
           qDebug() << "OLLEG: 3 NOT found";
       }

       jclass telephonyManagerClass = env->FindClass("android/telephony/TelephonyManager");
       if(telephonyManagerClass){
           qDebug() << "OLLEG: 4 found";
       }
       else{
           qDebug() << "OLLEG: 4 NOT found";
       }


       jmethodID methodId = env->GetMethodID(contextClass, "getSystemService", "(Ljava/lang/String;)Ljava/lang/Object;");
       if(methodId){
           qDebug() << "OLLEG: 5 found";
       }
       else{
           qDebug() << "OLLEG: 5 NOT found";
       }

       QAndroidJniObject qtActivityObj = QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative",  "activity", "()Landroid/app/Activity;");

       jobject telephonyManager = env->CallObjectMethod(qtActivityObj.object<jobject>(), methodId, telephonyManagerType);
       if(telephonyManager){
           qDebug() << "OLLEG: 6 found";
       }
       else{
           qDebug() << "OLLEG: 6 NOT found";
       }

       methodId = env->GetMethodID(telephonyManagerClass, "getDeviceId", "()Ljava/lang/String;");
       if(methodId){
           qDebug() << "OLLEG: 7 found";
       }
       else{
           qDebug() << "OLLEG: 7 NOT found";
       }

       jstring jstr = (jstring) env->CallObjectMethod(telephonyManager, methodId);
       if(jstr){
           qDebug() << "OLLEG: 8 found";
       }
       else{
           qDebug() << "OLLEG: 8 NOT found";
       }

       jsize len = env->GetStringUTFLength(jstr);
       char* buf_devid = new char[32];
       env->GetStringUTFRegion(jstr, 0, len, buf_devid);
       QString imei(buf_devid);
       delete buf_devid;
       return imei;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString Imei=getDeviceImei();
    if(Imei == "863691032193890"||Imei =="863691032198899"){
    MainWindow w;
    w.show();
    return a.exec();

}
   else{
       QMessageBox msgb;
             msgb.setText("Пиратство это плохо!");
             msgb.exec();
      return 02;
    }

}


