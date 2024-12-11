#include "editor.h"

#include <stdexcept>
#include <iostream>

Editor &Editor::getEditor(){
    static Editor editor;
    return editor;

}


void Editor::proces(std::shared_ptr<act::IAction> action){
    action->doo();
    undo_.push(action->returnUndoAction());
    while(!redo_.empty()){
        redo_.pop();
    }
}

void Editor::undo(){
    if(undo_.empty()){
        return;
    }
    undo_.top()->doo();
    redo_.push(undo_.top()->returnUndoAction());
    undo_.pop();
}

void Editor::redo(){
    if(redo_.empty()){
        return;
    }
    redo_.top()->doo();
    undo_.push(redo_.top()->returnUndoAction());
    redo_.pop();
}



ID Editor::genereytId(){
    return ithemCaont++;
}

