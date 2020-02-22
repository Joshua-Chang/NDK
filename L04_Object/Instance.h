//
// Created by JoshuaChang on 2020/2/21.
//

#ifndef LEARNC_INSTANCE_H
#define LEARNC_INSTANCE_H


class Instance {
private:
    static Instance* instance;
    Instance();

public:
    static Instance* getInstance();
};


#endif //LEARNC_INSTANCE_H
