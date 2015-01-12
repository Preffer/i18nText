#include <iostream>
#include "include/i18nText.h"

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
	try {
		Mat demo(150, 400, CV_8UC3, CV_RGB(0, 255, 0));
		namedWindow("demo", CV_WINDOW_NORMAL);
		i18nText i18n;
		if (i18n.setFont("/usr/share/fonts/truetype/wqy/wqy-microhei.ttc")) {
			cout << "Load fonts successfully." << endl;

			const wchar_t *msg = L"汉字 iw0ol1 ニホンゴ";
			cout << "Put ";
			int num = i18n.putText(demo, msg, Point(25, 50), CV_RGB(0, 0, 255));
			cout << num << " chars." << endl;
	
			const wchar_t *msg2 = L"조선말／朝鮮말，한국어／韓國語";
			cout << "Put another ";
			num = i18n.putText(demo, msg2, Point(25, 100), CV_RGB(255, 0, 0));
			cout << num << " chars." << endl;
		}
		imshow("demo", demo);
		waitKey();
	} catch (Exception e) {
		cout << e.what() << endl;
	}

	return EXIT_SUCCESS;
}
