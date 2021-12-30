#include <QCoreApplication>
#include "athhandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AthHandler authHandler;
    authHandler.setAPIKey("AIzaSyBjwqIfOr0A5fnW1_CygeIQbmgXaZD-duA");
//    authHandler.signUserUp("hieucuopbien123@gmail.com","hieucuopbien");//password ở đây là password vào ứng dụng chứ
    //kp password gmail
    authHandler.signUserIn("hieucuopbien123@gmail.com","hieucuopbien");

    return a.exec();
}
