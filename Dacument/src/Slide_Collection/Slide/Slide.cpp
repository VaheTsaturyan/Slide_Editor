#include "Slide.h"

Slide::IteratorOrthogonal Slide::beginOrthogonal()
{
    return orthogonals.begin();
}

Slide::IteratorOrthogonal Slide::endOrthogonal()
{
    return orthogonals.end();
}

Slide::IteratorCircle Slide::beginCircle()
{
    return circls.begin();
}

Slide::IteratorCircle Slide::endCircle()
{
    return circls.end();
}

Slide::IteratorLines Slide::begoinLines()
{
    return  lines.begin();
}

Slide::IteratorLines Slide::endLines()
{
    return  lines.end();
}

Slide::IteratorTexts Slide::beginText()
{
    return texts.begin();
}

Slide::IteratorTexts Slide::endText()
{
    return texts.end();
}




Slide::constIteratorOrthogonal Slide::cBeginOrthogonal()
{
    return orthogonals.cbegin();
}

Slide::constIteratorOrthogonal Slide::cEndOrthogonal()
{
    return orthogonals.cend();
}

Slide::constIteratorCircle Slide::cBeginCircle()
{
    return circls.cbegin();
}

Slide::constIteratorCircle Slide::cEndCircle()
{
    return circls.cend();
}

Slide::constIteratorLines Slide::cBegoinLines()
{
    return lines.cbegin();
}

Slide::constIteratorLines Slide::cEndLines()
{
    return lines.cend();
}

Slide::constIteratorTexts Slide::cBeginText()
{
    return  texts.cbegin();
}

Slide::constIteratorTexts Slide::cBndText()
{
    return texts.cend();
}
