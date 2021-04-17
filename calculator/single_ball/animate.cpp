#include "animate.h"
#include "constants.h"
#include <iostream>
using namespace std;
#include "system.h"


animate::animate():sidebar(WORK_PANEL, SIDE_BAR)

{
    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Graphing calculator!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will    

    //declare new graph info
    _test = new graph_info;
    system = System(_test);

    window.setFramerateLimit(60);

    mouseIn = true;


    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);

    cout<<"Geme CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    //gives me grid for the graph for the x
    x = sf::RectangleShape();
    x.setSize(sf::Vector2f(WORK_PANEL, 1));
    x.setPosition(sf::Vector2f(0, SCREEN_HEIGHT/2));
    x.move(sf::Vector2f(0, _test->otherY));
    x.setFillColor(sf::Color::White);
//    window.draw(x);
    //gives me grid for the graph for the y
    y = sf::RectangleShape();
    y.setSize(sf::Vector2f(1, SCREEN_HEIGHT));
    y.setPosition(sf::Vector2f(WORK_PANEL/2, 0));
//    y.move(sf::Vector2f(_test->otherX, 0));
    y.setFillColor(sf::Color::White);
//    window.draw(y);

    myTextLabel = sf::Text(_test->_equation, font);
    myTextLabel.setCharacterSize(20);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setColor(sf::Color::Red);
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));

    //gives plot the information from the graph_info
    _plottest = Plot(_test);


    cout<<"animate instantiated successfully."<<endl;
}


void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
//    system.Draw(window); <--- this draws circle

    //lines are created with circle shapes
    points = sf::CircleShape();
    points.setRadius(2.0);
    points.setPosition(sf::Vector2f(0,0));
    points.setFillColor(sf::Color::Cyan);
    window.draw(points);

    window.draw(x);
    window.draw(y);

    //plot points on the graph after changed origin
    Vector<sf::Vector2f> p;
    p = _plottest.get_cords(_test);

    while(!p.empty()){
        //plots at this position
        points.setPosition(p.pop_back());
        window.draw(points);
    }


    if (mouseIn){
        window.draw(mousePoint);
    }

    sidebar.draw(window);

    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)
    window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .
}

void animate::update(){
    //cause changes to the data for the next frame
    system.Step(command);
    command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

        //mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);

    }
}
void animate::render(){
       window.clear();
       Draw();
       window.display();
}


void animate::processEvents()
{
    string function;
    sf::Event event;
    float mouseX, mouseY;
    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
           switch (event.type)
           {
           // window closed
           case sf::Event::Closed:
               window.close();
               break;
           // key pressed
           case sf::Event::KeyPressed:
               switch(event.key.code){
                case sf::Keyboard::Left:
                   sidebar[SB_KEY_PRESSED] = "LEFT ARROW";
                   _test->set_origin(MOVE,0);
                   y.move(sf::Vector2f(MOVE, 0));

                   command = 4;
                   break;
               case sf::Keyboard::Right:
                   sidebar[SB_KEY_PRESSED] = "RIGHT ARROW";
                   _test->set_origin(-MOVE,0);
                   y.move(sf::Vector2f(-MOVE, 0));

                   command = 6;
                   break;
               case sf::Keyboard::Up:
                   sidebar[SB_KEY_PRESSED] = "UP ARROW";
                   _test->set_origin(0,MOVE);
                   x.move(sf::Vector2f(0, MOVE));

                   break;
               case sf::Keyboard::Down:
                   sidebar[SB_KEY_PRESSED] = "DOWN ARROW";
                   _test->set_origin(0,-MOVE);
                   x.move(sf::Vector2f(0, -MOVE));

                   break;
               case sf::Keyboard::Escape:
                   sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                   window.close();
                   break;
               case sf::Keyboard::R:
                   sidebar[SB_KEY_PRESSED] = "R: reset origin";
                   _test->_origin = sf::Vector2f(WORK_PANEL/2,SCREEN_HEIGHT/2);
                   y.setPosition(sf::Vector2f(WORK_PANEL/2, 0));
                   x.setPosition(sf::Vector2f(0, SCREEN_HEIGHT/2));

                   _test->otherX = 0;
                   _test->otherY = 0;
                   break;
               case sf::Keyboard::Enter:
                   sidebar[SB_KEY_PRESSED] = "ENTER: input expression";
                   cout<<"enter in console: ";
                   cin>>function;
                   _test->_equation = function;
                   //redraw the new screen with new equation
                   _plottest = Plot(_test);
                   //change equation on screen
                   myTextLabel = sf::Text(_test->_equation, font);
                   myTextLabel.setCharacterSize(20);
                   myTextLabel.setStyle(sf::Text::Bold);
                   myTextLabel.setColor(sf::Color::Red);
                   myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));

                   //update the screen
                   break;
               case sf::Keyboard::O:
                   sidebar[SB_KEY_PRESSED] = "O: zoom out";
                   //zoom out
                   break;
               case sf::Keyboard::I:
                   sidebar[SB_KEY_PRESSED] = "I: zoom in";
                   //zoom in
                   break;
               case sf::Keyboard::Num1:
                   sidebar[SB_KEY_PRESSED] = "1: file saved";
                   save();
                   cout<<"file saved: "<<endl;
                   command =11;
                   break;
               case sf::Keyboard::Num2:
                   sidebar[SB_KEY_PRESSED] = "2: file load";
                   load();
                   cout<<"file loaded: "<<endl;
                   break;
               case sf::Keyboard::Num3:
                   sidebar[SB_KEY_PRESSED] = "3: file cleared";
                   clear_file();
                   cout<<"file cleared: "<<endl;
                   break;
               }
               break;
           case sf::Event::MouseEntered:
               mouseIn = true;
               break;

           case sf::Event::MouseLeft:
               mouseIn = false;
               break;

           case sf::Event::MouseMoved:
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                //Do something with it if you need to...
               break;
           case sf::Event::MouseButtonReleased:
                   if (event.mouseButton.button == sf::Mouse::Right)
                   {
                       sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
                               mouse_pos_string(window);

                   }
                   else{
                       sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                               mouse_pos_string(window);
                   }
                   break;
               default:
                   break;
           case sf::Event::MouseButtonPressed:
               std::cout<< "mouse pressed at X: "<<event.mouseButton.x<<"Y: "<<event.mouseButton.y<<std::endl;
               //for saved functions
               if(event.mouseButton.x >850 && event.mouseButton.x<940){
                   if(event.mouseButton.y>100 && event.mouseButton.y<140){
                       save();
                       cout<<"Save was pressed"<<endl;
                   }
               }
               //box5 = [LOAD]
               if(event.mouseButton.x >850 && event.mouseButton.x<940){
                   if(event.mouseButton.y>205 && event.mouseButton.y<240){
                       load();
                       cout<<"Load was pressed"<<endl;
                   }
               }
               break;

           }
       }
}
void animate::save(){
    //step 1: declare: ofstream, write on files
    ofstream saveFile;

    //step 2: open
    saveFile.open("saveFile.txt", ios::app);


    //Step 3: Fail safe
    if (saveFile.fail()){
        cout<<"Could not open input file..."<<endl;
        exit(1);
    }

    //step 4: Read
    saveFile<<_test->_equation<< '\n';

    //Step 5: Close
    saveFile.close();   //closes after finishes the read
}
void animate::load(){
    //Step 1: Declare: ifstream, read from files
    ifstream inputFile;
    string line;

    //Step 2: Open:
    inputFile.open("SaveFile.txt");

    //Step 3: Fail safe
    if(inputFile.fail()){
        cout<<"Could not open output file..."<<endl;
    }

    //Step 4: Read
    if (inputFile.is_open() ) {
        while ( getline (inputFile,line) ) {
            cout << line << '\n';
        }
    }

    //Step 5: Close
    inputFile.close();

}
void animate::clear_file(){
    //step 1: declare file
    ofstream saveFile;

    //step 2: open
    saveFile.open("saveFile.txt", ios::app);


    //Step 3: Fail safe
    if (saveFile.fail()){
        cout<<"Could not open output file..."<<endl;
        exit(1);
    }
    //step 4: clear file
    saveFile.clear();

    //step 5: close
    saveFile.close();
}
void animate::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   delete _test;

   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}
