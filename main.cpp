#include <iostream>
#include <fstream>

using namespace std;

class Vehicle
{
    public:

        Vehicle(){}
        virtual string getEngine()=0;
        virtual void set_engine(string engine)=0;

};

class Decorated_object
{
    public:

        Decorated_object() {}
        virtual void set_color(string object_color)=0;
        virtual void set_speed(int speed)=0;
        virtual string get_color()=0;
        virtual int get_speed()=0;

};

class Car : public Vehicle, public Decorated_object
{

    public:
        string _engine;
        string _car_color;
        int speed_;

        Car(string diesel, string car_color, int speed):
            _engine(diesel), _car_color(car_color), speed_(speed){}

        virtual string getEngine(){
        return _engine;
        }

        virtual void set_engine(string engine){
            _engine = engine;
        }

        virtual void set_color(string object_color){
            _car_color=object_color;
        }

        virtual void set_speed(int speed){
        speed_ = speed;
        }

        virtual string get_color(){
        return _car_color;
        }

        virtual int get_speed(){
        return speed_;
        }

        ~Car();
};

class Sport_car : public Car
{

    public:
        void increse_speed(int speed)
        {
            speed_=2*speed;
        }
        Sport_car();
        ~Sport_car();

};

class File {

    public:
    ofstream* my_file;
    string location;

        class Content{

        private:
            string text_;
        public:

            string get_text(){
                return text_;
            }

            void set_text(string text){
                text_ = text;
        }

            Content(){}
            ~Content(){}

        };

    public:
    File(string _location){
        my_file = new ofstream;
    }

    void create_myfile(Car* );

    void load_content(Car*);

    ~File()
    {
        delete my_file;
    }

};

    void File::create_myfile(Car* car){
        my_file->open("animation.html");
        load_content(car);
        my_file->close();
        }

    void File::load_content(Car *car){

    string content = string("<!DOCTYPE html>")+
        string("<html>")+
        string("<body>")+
        string("<svg width=\"1000\" height=\"200\" style=\"background: green\">")+


        string("<!-- Top -->")+
        string("<rect id = \"Top\" x=\"60\" y=\"10\" width=\"220\" height=\"130\" fill=\"transparent\" rx=\"150\" stroke=\"")+car->get_color()+string("\" stroke-width=\"10\" />")+

        string("<!-- Body -->")+
        string("<rect id=\"Body\" x=\"10\" y=\"70\" width=\"340\" height=\"80\" fill=\"")+car->get_color()+string("\" rx=\"30\" />")+


        string("<!-- Left wheel -->")+
        string("<g>")+
        string("<circle id=\"Left wheel\" r=\"40px\" fill=\"#222\" stroke=\"white\" stroke-width=\"7\" cx=\"90\" cy=\"140\"/>")+

        string("<!-- Right wheel -->")+
        string("<g>")+
        string("<circle id=\"Right wheel\" r=\"40px\" fill=\"#222\" stroke=\"white\" stroke-width=\"7\" cx=\"270\" cy=\"140\"/>")+

        string("<circle id=\"innerCircle\" cx = \"340\" cy = \"85\" r = \"5\" fill = \"yellow\">")+
        string("<animate ")+
        string("attributeName=\"r\" begin=\"0s\" dur=\"1s\" repeatCount=\"indefinite\" from=\"5\" to=\"18\" />")+
        string("<animate ")+
        string("xlink:href=\"#innerCircle\" attributeName=\"cx\"from=\"340\"to=\"970\" dur=\"")+to_string(car->get_speed())+string("s\" begin=\"0\" fill=\"freeze\" id=\"l-anim\"repeatCount=\"indefinite\"/>")+

        string("<animate ")+
        string("xlink:href=\"#Top\" attributeName=\"x\"from=\"60\"to=\"690\" dur=\"")+to_string(car->get_speed())+string("s\" begin=\"0\" fill=\"freeze\" id=\"top-anim\" repeatCount=\"indefinite\"/>")+

        string("<animate " )+
        string("xlink:href=\"#Body\" attributeName=\"x\"from=\"10\"to=\"640\" dur=\"")+to_string(car->get_speed())+string("s\" begin=\"0\" fill=\"freeze\" id=\"body-anim\" repeatCount=\"indefinite\"/>")+

        string("<animate ")+
        string("xlink:href=\"#Left wheel\" attributeName=\"cx\" from=\"90\" to=\"720\"dur=\"")+to_string(car->get_speed())+string("s\" begin=\"0\" fill=\"freeze\"id=\"lwheel-anim\" repeatCount=\"indefinite\"/>")+

        string("<animate ")+
        string("xlink:href=\"#Right wheel\" attributeName=\"cx\" from=\"270\" to=\"900\" dur=\"")+to_string(car->get_speed())+string("s\" begin=\"0\" fill=\"freeze\" id=\"rwheel-anim\" repeatCount=\"indefinite\"/>")+

        string("</svg>")+

        string("</body>")+
        string("</html>");
            (*my_file) << content;
        }


int main()
{
    cout<<"Podaj czas trwania animacji [s]"<<endl;

    string color = "crimson";
    string engine ="diesel";
    int speed;
    cin>>speed;

    string location = "animation2.html";

    Car* car = new Car(engine,color, speed);
    File* myfile = new File(location);
    myfile->create_myfile(car);

        return 0;
}


