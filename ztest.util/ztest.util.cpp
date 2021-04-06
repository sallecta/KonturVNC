// classes example
#include <iostream>

#include "../util/ztest.util.common.h"
#include "../util/CommonHeader.h"


int main () {
  testClass1 inst1;
  testClass2 inst2;
  inst1.testFn();
  inst2.testFn();

  StringStorage testStringStorage(_T("emm"));
  return 0;
}
