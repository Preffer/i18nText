#include <iostream>
#include "include/i18nText.h"

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
	try {
		Mat demo(150, 400, CV_8UC3, CV_RGB(0, 255, 0));
		namedWindow("demo", CV_WINDOW_NORMAL);
		i18nText i18n("wqy-microhei.ttc");
		cout << "Load fonts successfully." << endl;

		wstring msg = L"汉字 iw0ol1 ニホンゴ";
		int num = i18n.putText(demo, msg, Point(25, 50), CV_RGB(0, 0, 255));
		cout << "Put " << num << " chars." << endl;
	
		msg = L"조선말／朝鮮말，한국어／韓國語";
		num = i18n.putText(demo, msg, Point(25, 100), CV_RGB(255, 0, 0));
		cout << "Put another " << num << " chars." << endl;

		imshow("demo", demo);
		waitKey();
	} catch (const exception& e) {
		cout << e.what() << endl;
	}

	return EXIT_SUCCESS;
}
