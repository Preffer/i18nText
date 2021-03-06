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
		i18n.putText(demo, msg, Point(25, 50), Vec3b(0, 0, 255));
	
		msg = L"조선말／朝鮮말，한국어／韓國語";
		i18n.putText(demo, msg, Point(25, 100), Vec3b(255, 0, 0));

		cout << "Put text successfully." << endl;
		imshow("demo", demo);
		waitKey();
	} catch (const exception& e) {
		cout << e.what() << endl;
	}

	return EXIT_SUCCESS;
}
