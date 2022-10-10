#include "Message.h"
#include "Application.h"

using namespace std;

int main()
{
    Application* stack1 = new Application();
    Application* stack2 = new Application();
    Application* stack3 = new Application();

    config cfg1 = config();
    config cfg2 = config();
    config cfg3 = config();

    cfg1.computerName = "Comp 1";
    cfg1.DestIP = "192.168.0.1";
    cfg1.encoding = "UTF-8";
    cfg1.ip = "127.0.0.1";
    cfg1.port = "300";
    cfg1.DestPort = "400";

    cfg2.computerName = "Comp 2";
    cfg2.DestIP = "192.168.0.2";
    cfg2.encoding = "UTF-8";
    cfg2.ip = "127.0.0.2";
    cfg2.port = "300";
    cfg2.DestPort = "500";

    cfg3.computerName = "Comp 3";
    cfg3.DestIP = "127.0.0.1";
    cfg3.encoding = "UTF-8";
    cfg3.ip = "192.168.0.1";
    cfg3.port = "400";
    cfg3.DestPort = "300";

    stack1->configure(cfg1);
    stack2->configure(cfg2);
    stack3->configure(cfg3);

    stack1->link(stack2);
    stack2->link(stack3);

    cout << "Test 1 successfull" << endl;
    stack1->execute("An example test message", 23);
    

    delete stack1;
    delete stack2;
    delete stack3;
}

/*Output:
Test 1 successfull
Message at Physical layer of computer: Comp 2
Message at Datalink layer
Message at Network layer
Message at Physical layer of computer: Comp 3
Message at Datalink layer
Message at Network layer
Message at Transport layer
Message at Presentation layer on computer: Comp 3
Computer Comp 3 Received message: An example test message
*/