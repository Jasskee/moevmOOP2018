#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <iostream>

using namespace std;

template <typename T>   class List;
template <typename T> class Iterator;

//--------------CLASS-ELEM-----------------
template <typename T>
class Elem {
    friend class List<T>;
    friend class Iterator<T>;
private:
    T info;
    Elem *prev;
    Elem *next;
public:
    Elem(T const &inf) : info(inf), prev(nullptr), next(nullptr) {};

    T       &get_Info()       {return info; }
    const T &get_Info() const {return info; }

    Elem<T> &operator= ( T const &r);
};
//--------------CLASS-ELEM-----------------

//--------------CLASS-LIST-----------------
template <typename T>
class List {
    friend class Iterator<T>;
private:
    Elem<T> *head;
    Elem<T> *tail;
public:
    List():head(nullptr), tail(nullptr){};  //Constructor
    ~List();                                //Destructor
    bool is_Empty();
    void Print_List();

    void Add_After(T const &data, size_t k);   // Elem(
    void Add_to_Head(T const &data);
    void Add_to_Tail(T const &data);

    void delete_one(); //удаление если единственный элемент
    void Delete_from_tail();
    void Delete_from_head();
    void Delete_elem(size_t k);

    size_t  Quantity();

    Elem<T> *Init(T const &data);
    Elem<T> *get_Elem(size_t index);

    T       operator[] (size_t index);
    Iterator<T> begin(){    return Iterator<T>(head);    }
    Iterator<T> end()  {    return Iterator<T>(nullptr); }
};
//--------------CLASS-LIST-----------------

//---------------OPERATOR-[]----------------
template <typename T>
T List<T>::operator[](size_t index){
    // try{
    //     return get_Elem(index)->info;
    // }catch(const  std :: exception & e){
    //     std::cout << e.what() << "\n";
    // }
    Elem<T> *t = get_Elem(index);
    //if(t)
        return t->info;
}

//---------------OPERATOR-=----------------
template <typename T>
Elem<T> &Elem<T>::operator= (T const &r){
    get_Info() = r;
    return *this;
}

//---------------OPERATOR-<<-and->>--------------
template <typename T>
istream &operator>> (istream &in, Elem<T> &el){
    in >> el.get_Info();
    return in;
}

template <typename T>
ifstream &operator>> (ifstream &fin, Elem<T> &el){
    fin >> el.get_Info();
    return fin;
}

template <typename T>
ostream &operator<< (ostream &out, const Elem<T> &el){
    out << el.get_Info() << '\n';
    return out;
}

template <typename T>
ofstream &operator<< (ofstream &fout, const Elem<T> &el){
    fout << el.get_Info() << '\n';
    return fout;
}
//----------------------------------------------

//***********FUNCTON*OF*LIST********************
template <typename T>
List<T>::~List(){
    Elem<T> *tmp;
    if (!is_Empty())
        while (head) {
            tmp = head;
            head = head->next;
            delete tmp;
        }
}

template <typename T>   //Check at empty
bool List<T>::is_Empty(){
    return head == nullptr;
}

template <typename T>
Elem<T> *List<T>::get_Elem(size_t index){
    size_t count = 0;
    Elem<T> *tmp = head;
    while (count < index) {
        tmp = tmp->next;
        count++;
    }
    return tmp;
}

template <typename T>   //Printing of list
void List<T>::Print_List() {
    Elem<T> *tmp = head;
    if (is_Empty()) {
        std::cout << "List is epmty!" << endl;
    }else
        while(tmp){
            std::cout << "[" << tmp->info << "] " << endl;
            tmp = tmp->next;
        }
}

template <typename T>   //Size of list
size_t List<T>::Quantity() {
    Elem<T> *tmp = head;    size_t q = 0;
        while(tmp){
            tmp = tmp->next; //написать рекурсивную реализацию
            q++;
        }
    return q;
}


template <typename T>   //Initialization new elemen
Elem<T> *List<T>::Init(T const &data){
    Elem<T> *p = new Elem<T>(data);
    return p;
}

template <typename T>   //Adding new element
void List<T>::Add_to_Head(T const &data){
    Elem<T> *new_p = Init(data);
    if(is_Empty()){
        head = new_p;
        tail = new_p;
    }
    else {
        new_p->next = head;
        head->prev = new_p;
        head = new_p;
    }

}

template <typename T>   //Adding new element
void List<T>::Add_to_Tail(T const &data){
    Elem<T> *new_p = Init(data);
    if( is_Empty() )
        Add_to_Head(data);
    else{
        new_p->prev = tail;
        tail->next = new_p;
        tail = new_p;
    }
}

template <typename T>   //Adding new element
void List<T>::Add_After(T const &data, size_t k){

    size_t s = Quantity();
    Elem<T> *tmp, *new_p;
    if(is_Empty() || k == 0 )
        Add_to_Head(data);
    else if(k >= s)
        Add_to_Tail(data);
    else if(k >= 1   &&   k < s){
        new_p = Init(data);
        tmp = get_Elem(k-1);

        new_p->prev = tmp;
        new_p->next = tmp->next;
        tmp->next->prev = new_p;
        tmp->next = new_p;
    }
}

template <typename T>
void List<T>::delete_one(){
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void List<T>::Delete_from_head(){
    if(!is_Empty()){
        Elem<T> *temp = head;
        if (Quantity()== 1)
            delete_one();
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        temp->next = nullptr;
        delete temp;
    }else
        std::cout << "List is empty!" << '\n';
}

template <typename T>
void List<T>::Delete_from_tail(){
    if(!is_Empty()){
        Elem<T> *temp = tail;
        if (Quantity() == 1)
            delete_one();
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        temp->prev = nullptr;
        delete temp;
    }else
        std::cout << "List is empty!" << '\n';
}

template <typename T>
void List<T>::Delete_elem(size_t k){
    size_t s = Quantity();
    Elem<T> *tmp;

    if(is_Empty() || k == 0 )
        Delete_from_head();
    else if(k >= s -1)
        Delete_from_tail();
    else if(k >= 1   &&   k < s){
        tmp = get_Elem(k);
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
    }
}
//*********************************************

#endif //MY_VECTOR_HPP
