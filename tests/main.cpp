//
// Created by NILANJAN GOSWAMI on 11/11/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "TestCase.hpp"


TEST_CASE( "TC1", "[testSampleAdd]" ) {
  auto result = NsTest::testStatSampleAdd();
  REQUIRE(result.first == result.second);
}
