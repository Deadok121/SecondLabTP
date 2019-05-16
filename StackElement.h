//
// Created by Roman Oborin on 2019-05-16.
//

#ifndef SECONDLABTP_ELEMENT_H
#define SECONDLABTP_ELEMENT_H
class StackElement {
private:
    int data{};
    StackElement *previous{};

public:
    explicit StackElement(int data) {
        this->data = data;
    }

    StackElement() = default;;

    StackElement *getPrevious() const {
        return previous;
    }

    void setPrevious(StackElement *previous) {
        this->previous = previous;
    }

    int getData() {
        return data;
    }

};


#endif //SECONDLABTP_ELEMENT_H
