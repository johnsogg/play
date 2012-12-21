#include <stdio.h>

#include "RetroPrinter.h"

using ::testing::EmptyTestEventListener;
using ::testing::UnitTest;
using ::testing::TestInfo;
using ::testing::TestPartResult;

void RetroPrinter::OnTestProgramStart(const UnitTest& /*unit_test*/ ) { }

  // Called after all test activity ends
void RetroPrinter::OnTestProgramEnd(const UnitTest& unit_test) {
  fprintf(stdout, "Retro> TEST %s\n", unit_test.Passed() ? "PASSED" : "FAILED");
  fflush(stdout);
}

  // called before an individual test case starts
void RetroPrinter::OnTestStart(const TestInfo& test_info) {
  fprintf(stdout,
	  "Retro> *** Test %s.%s starting.\n",
	  test_info.test_case_name(),
	  test_info.name());
  fflush(stdout);
}

  // called after a failed assertion or a SUCCEED() invocation
void RetroPrinter::OnTestPartResult(const TestPartResult& test_part_result) {
  fprintf(stdout,
	  "Retro> %s in %s:%d\n%s\n",
	  test_part_result.failed() ? "*** Failsauce" : "Success",
	  test_part_result.file_name(),
	  test_part_result.line_number(),
	  test_part_result.summary());
  fflush(stdout);
}

// called after a unit test case ends
void RetroPrinter::OnTestEnd(const TestInfo& test_info) {
  fprintf(stdout,
	  "Retro> *** Test %s.%s ending.\n",
	  test_info.test_case_name(),
	  test_info.name());
  fflush(stdout);
}

