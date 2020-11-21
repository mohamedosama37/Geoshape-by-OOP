#include <iostream>

using namespace std;

class Geoshape
{
protected:
    float dim1;
    float dim2;
public:
    Geoshape()
    {
        dim1=dim2=0;
            cout<<"this is default geo constructor "<<endl;
    }
    Geoshape(float x)
    {
        dim1=dim2=x;
            cout<<"this is default geo constructor with one parameter "<<endl;
    }
    Geoshape(float x , float y)
    {
        dim1=x;
        dim2=y;
        cout<<"this is default geo constructor with two parameter "<<endl;
    }
    void setdim1(float x)
    {
        dim1=x;
    }
    void setdim2(float y)
    {
        dim2=y;
    }
    float getdim1()
    {
        return dim1;
    }
    float getdim2 ()
    {
        return dim2;
    }
  virtual  float calculatearea ()
  {
      return 0;
  }

    ~Geoshape()
    {
     cout<<"this is default geo destructor "<<endl;
    }

};

class Triangle :public Geoshape
{
public :
    Triangle(float b, float h) : Geoshape(b,h)
    {
        cout<<"this is  constructor with 2 parameter"<<endl;
    }
    Triangle(float b) : Geoshape(b)
    {
         cout<<"this is  constructor with 1 parameter"<<endl;
    }
    Triangle():Geoshape()
    {
           cout<<"this is default constructor"<<endl;
    }

    float calculatearea()
    {
        return 0.5 * dim1 *dim2;
    }
    ~Triangle()
    {
        cout<<"this is default destructor"<<endl;
    }

};


class Rect:public Geoshape
{
    public:
    Rect():Geoshape()
    {
         cout<<"this is   cout default constructor  "<<endl;
    }
    Rect(float x): Geoshape( x)
    {
         cout<<"this is  constructor with 1 parameter"<<endl;
    }
    Rect(float x, float y):Geoshape(x,y)
    {
        cout<<"this is  constructor with 2 parameter"<<endl;
    }
    float calculatearea()
    {
        return dim1 *dim2;
    }
    ~Rect()
    {
        cout<<"this is default destructor"<<endl;
    }
};

class circle :public Geoshape
{
public:
    circle()
    {

    }
    circle(float r):Geoshape(r)
    {

    }
    void setradius(float r)
    {
        dim1=dim2=r;
    }
    float getradius()
    {
        return dim1;
    }
    float calculatearea()
    {
        return 22/7 *dim1*dim2;
    }
};


class Square :public  Rect
{
public:
    Square (float x):Rect(x)
    {

    }
    void setsquaredim(float x)
    {
        dim1=dim2=x;
    }
    float getsquaredim ()
    {
        return dim2;
    }
    float calculatearea()
    {
        return Rect::calculatearea();
    }
};
float sumofareas(int s , Geoshape** p)
{
    int i;
    float sum=0;
    for(i=0;i<s;i++)
    {
        sum+=p[i]->calculatearea();
    }
    return sum;
}
int main()
{
   Geoshape**ptr=new Geoshape*[4];

    Rect r1(5,6);
    ptr[0]=& r1;



    circle c1(4);
    ptr[1]=& c1;



    Square s1(4);
     ptr[2]=& s1;


    Triangle t1(3,4);
 ptr[3]=& t1;

    cout<<sumofareas(4,ptr)<<endl;
}




