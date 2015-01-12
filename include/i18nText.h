#ifndef _I18N_TEXT_H_
#define _I18N_TEXT_H_

#include <opencv2/highgui/highgui.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H
#include <cwchar>


using namespace std;
using namespace cv;

struct SizeDesc {
    float pixelSize;  /// Size of character.
    float space;   /// Default width of character. Only used when FT_Render_Glyph() failed to get character width.
    float gap;  /// Gap between characters.
};

class i18nText {
public:
    i18nText();
    ~i18nText();
    bool isValid(void);
    bool setFont(const char* name);
    void setSize(SizeDesc* size = NULL);
    int putText(Mat& img, const wchar_t* text, Point pos, Scalar color = CV_RGB(0, 0, 0));

private:
    void putWChar(Mat& img, wchar_t wc, Point& pos, Scalar color);

    static int counter;
    static FT_Library library;
    bool valid;
    FT_Face face;
    SizeDesc size;
};

#endif // _I18N_TEXT_H_
