#include "sidebar.h"
#include "constants.h"
#include <cstring>
Sidebar::Sidebar(){

}

Sidebar::Sidebar(float left, float width):_left(left), _width(width){
    cout<<"Sidebar CTOR: TOP"<<endl;
    items.reserve(50);

    //set up the sidebar rectangle:
    rect.setFillColor(sf::Color(255,128,10)); //(192,192,192)); //silver
    rect.setPosition(sf::Vector2f(left, 0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));
    cout<<"Sidebar CTOR: about to load font."<<endl;

    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    //the font file must be in the "working directory"
    // check projects->run->working directory
    //      [Make sure it's not pointing to the app file]

    if (!font.loadFromFile("Roboto-Thin.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout<<"Sidebar CTOR: loaded font."<<endl;

    //. . . . . text / font problems: . . . . . . . .
    //initializing text object in this way caused problems
    // (hangs!)
    //only when sb_text was a private member and worked fine
    //when it was a public member. Probably not releavant,
    //but still strange!
    //
    //sb_text = sf::Text("Initial String for myTextLabel", font);
    //
    //. . . . . . . . . . . . . . . . . . . . . . . . .
    cout<<"Sidebar CTOR: Text object initialized."<<endl;
    sb_text.setFont(font);
    sb_text.setCharacterSize(20);
    sb_text.setStyle(sf::Text::Bold);
    sb_text.setColor(sf::Color::Yellow);

    fnc = sf::Text("Load", font);
    fnc.setFont(font);
    fnc.setCharacterSize(20);
    fnc.setStyle(sf::Text::Bold);
    fnc.setColor(sf::Color::Red);

    fnc2 = sf::Text("Save", font);
    fnc2.setFont(font);
    fnc2.setCharacterSize(20);
    fnc2.setStyle(sf::Text::Bold);
    fnc2.setColor(sf::Color::Red);

    ////this is how you would position text on screen:
    //sb_text.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-sb_text.getLocalBounds().height-5));

    items.push_back("sidebar sample text");
    //Fill the items vector with empty strings so that we can use [] to read them:
    for (int i=0 ; i<30; i++){
        items.push_back("");
    }
    cout<<"Sidebar: CTOR: Exit."<<endl;
}

void Sidebar::draw(sf::RenderWindow& window){
    const double VERTICAL_LINE_SPACING = 5.0;
    const double LEFT_MARGIN = 10.0;

    window.draw(rect);
    Boxes(window);

    float height = 10;

    for (vector<string>::iterator it = items.begin();
                                it!= items.end(); it++){
        bool blank = false;
        if (strlen(it->c_str()) == 0){
            //empty rows must be taken into account (getLocalBounds())
            //    but not drawn
            blank = true;
//            fnc.setString("BLANK");
            sb_text.setString("BLANK");
        }
        else{
            sb_text.setString(it->c_str());
        }
        sb_text.setPosition(sf::Vector2f(_left+LEFT_MARGIN, height));
        fnc.setPosition(sf::Vector2f(_left+LEFT_MARGIN+50, height-410));
        fnc2.setPosition(sf::Vector2f(_left+LEFT_MARGIN+50, height-510));

        height += sb_text.getLocalBounds().height+VERTICAL_LINE_SPACING;
        if (!blank){
            window.draw(sb_text);
        }
    }
    window.draw(fnc);
    window.draw(fnc2);

}
void Sidebar::Boxes(sf::RenderWindow& window){
    const sf::Vector2f boxSize(90, 40);
    for(int i=100; i<300; i+=100){
        sf::RectangleShape box; //initiz=alizer for box
        box.setPosition(850,i); //sets position for my box, starting placehold is i
        box.setSize(boxSize);   //box size is declared before
        box.setFillColor(sf::Color::White);
        box.setOutlineThickness(1);
        box.setOutlineColor(sf::Color::Black);
        window.draw(box);

    }
}

string& Sidebar::operator [](int index){
    return items[index];
}
