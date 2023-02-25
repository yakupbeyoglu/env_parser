#include <gtest/gtest.h>

#undef ASSERT_FALSE
#undef ASSERT_ALL
#include "../src/data.h"
#include <gtest/gtest.h>

TEST(DATA_TO_LOWER, BasicAssertions) {
    EXPECT_TRUE(EnvParser::data::to_lower("TRuE") == "true");
    EXPECT_TRUE(EnvParser::data::to_lower("true") == "true");
    EXPECT_TRUE(EnvParser::data::to_lower("123") == "123");
}

TEST(DATA_CONVERSION_THROW_TEST, BasicAssertions) {
    EnvParser::data data("test");
    try {
        float converted = float(data);
        FAIL();
    }catch(const std::exception &exception) {}
  
    try {
        double converted = double(data);
        FAIL();
    }catch(const std::exception &exception) {}
    
    try {
        int converted = int(data);
        FAIL();
    }catch(const std::exception &exception) {}
    
    try {
        bool converted = bool(data);
        FAIL();
    }catch(const std::exception &exception) {}
        
}

TEST(DATA_CONVERSION_TEST, BasicAssertions) {
    EXPECT_TRUE(bool(EnvParser::data("true")) == true);
    EXPECT_TRUE(bool(EnvParser::data("tRUe")) == true);
    EXPECT_TRUE(bool(EnvParser::data("false")) == false);
    EXPECT_TRUE(bool(EnvParser::data("0")) == false);
    EXPECT_TRUE(bool(EnvParser::data("1")) == true);        
}

