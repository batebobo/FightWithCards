#ifndef SHOP_H
#define SHOP_H

class Shop
{
    public:
        Shop(char* ="" , int = 0 );
        virtual ~Shop();

        void setName(char*);
        void receiveMoney(int);
        void addProduct(const Product&);//добавяне на нови количеста или на нов продукт
        void getProduct(Product&)//взимане на продукт от базата на магизина и прибавяне към кошницата на клиент

        char* getName()const {return name;}
        double getMoney()const {return money;}


    private:
        char *name;//името на магазина
        int money;// капиталът с който магазина разполага
        int numberProducts;//колко продукти имаме в момента;
        int capacity;//максималният брой продукти - трябва ми за да знам кога да разширявам паметта
        Product* products;
        void destroy();
        void resize();
        bool empty();
        bool isProductContainerFull();
};

#endif // SHOP_H
