#include "application.h"

Application::Application()
{
    slide = std::make_shared<Slide>();
    controler = std::make_shared<Controler>();
    editor = std::make_shared<Editor>();
    sterializer = std::make_shared<Sterializer>();
}

int Application::exec()
{
    editor->setSlide(slide);
    controler->setEditor(editor);
    controler->setSterilizer(sterilizer);
    controler->startProces();
    return 0;
}