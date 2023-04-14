//
// Created by Paolo Octoman on 3/15/23.
//

#include "TextInput.h"
#include "../Helpers/KeyBoardShortCuts.h"

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(box);
    window.draw(text);
    if (time.asSeconds() < 0.5){
        window.draw(cursor);
    }

}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    box.addEventHandler(window,event);
    cursor.hide();
    if (box.state.checkState(CLICKED)){
        text.addEventHandler(window, event);
        cursor.show();
    }



}

void TextInput::update() {
    cursor.setRelativePosition(text, box);
    text.update();
//    History::push(this, getSnapshot());
}





TextInput::TextInput() {
    box.setSize(text);
    box.setLabel("Type Something!:");
    text.setPosition(box.getPosition().x,box.getPosition().y);
}

void TextInput::setCharacterSize(unsigned int size) {
    text.setLetterSize(size);
    box.setSize(size);
    cursor.setCharacterSize(box.getSpacerSize());
}

void TextInput::setLength(float length) {
    box.setLength(length);
    text.setLength(length);

}

void TextInput::setLabel(std::string label) {
    box.setLabel(label);
}

TextInput::TextInput(unsigned int size, float length, std::string label, float x, float y) : TextInput(){
    setCharacterSize(size);
    setLength(length);
    setLabel(label);
    setPosition(x,y);
}

void TextInput::setPosition(float x, float y) {
    text.setPosition(x,y);
    box.setPosition(x,y);
    cursor.setRelativePosition(text,box);

}

sf::FloatRect TextInput::getGlobalBounds() const{
    return box.getGlobalBounds();
}

void TextInput::getTime(sf::Time time) {
    this->time = time;
}

TextInput::TextInput(const TextInput & ti) {
    *this = ti;
}

void TextInput::applySnapshot(Snapshot *snapshot) {
//    TextInput* temp = (dynamic_cast<TextInput*>(History::topHistory()->getObj()));
//    text = temp->text;
//    box = temp->box;
//
//    cursor = temp->cursor;
//
//     time = temp->time;
}

Snapshot *TextInput::getSnapshot() {
//    GUI_Component* gc = this;
//    Snapshot snap;
//    snap.setObject(gc);
//    Snapshot* ptr = &snap;
//    return ptr;
}

std::string TextInput::getText() {
    return text.getText();
}

bool TextInput::isClicked() {
    return box.state.checkState(CLICKED);
}

