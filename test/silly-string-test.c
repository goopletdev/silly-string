#include "silly-string.h"
#include "unity.h"

static silly_string* root;

void setUp(void) {
    root = silly_string_init();
    silly_string_insert(root, "apple", "fruit");
    silly_string_insert(root, "tree", "forest is made of ____");
    silly_string_insert(root, "house", "she lives in a _____");
    silly_string_insert(root, "apparent", "it's ________ you're a parent when...");
    silly_string_insert(root, "hOuSE", "HoUse");
    silly_string_insert(root, "HOUSE", "house");
    silly_string_insert(root, "it's ____ to see you AGAIN!", "nice");

    silly_string_insert_caps(root, "capstest_1", "ct1 result 1");
    silly_string_insert_caps(root, "capstest_2", "ct2 result 2");
}

void tearDown(void) {

}

void sillyStringGet_should_getCaseSensitiveKeyValues(void) {
    TEST_ASSERT_EQUAL_STRING("fruit", silly_string_get(root, "apple"));
    TEST_ASSERT_EQUAL_STRING("forest is made of ____", silly_string_get(root, "tree"));
    TEST_ASSERT_EQUAL_STRING("HoUse", silly_string_get(root, "hOuSE"));
    TEST_ASSERT_NULL(silly_string_get(root, "TREE"));
    TEST_ASSERT_NULL(silly_string_get(root, "House"));
    TEST_ASSERT_NULL(silly_string_get(root, "it's ____ to see you again!"));
    TEST_ASSERT_EQUAL_STRING("nice", silly_string_get(root, "it's ____ to see you AGAIN!"));

    TEST_ASSERT_NULL(silly_string_get(root, "capstest_1"));
    TEST_ASSERT_NOT_NULL(silly_string_get(root, "CAPSTEST_1"));
}

void sillyStringGetCaseInsensitive_should_getCaseInsensitiveKeyValues(void) {
    TEST_ASSERT_EQUAL_STRING("fruit", silly_string_get_case_insensitive(root, "apple"));
    TEST_ASSERT_EQUAL_STRING("fruit", silly_string_get_case_insensitive(root, "Apple"));
    TEST_ASSERT_EQUAL_STRING("fruit", silly_string_get_case_insensitive(root, "APPLE"));
    TEST_ASSERT_EQUAL_STRING("it's ________ you're a parent when...", silly_string_get_case_insensitive(root, "ApPaReNT"));
    TEST_ASSERT_EQUAL_STRING("nice", silly_string_get_case_insensitive(root, "it's ____ to see you again!"));

    TEST_ASSERT_EQUAL_STRING("ct1 result 1", silly_string_get_case_insensitive(root, "capstest_1"));
}

void sillyStringGetCaps_should_getCaseInsensitiveKeyValuesFromCapsInsertion(void) {
    TEST_ASSERT_EQUAL_STRING("ct1 result 1", silly_string_get_caps(root, "capstest_1"));
    TEST_ASSERT_EQUAL_STRING("ct2 result 2", silly_string_get_caps(root, "capstest_2"));
    TEST_ASSERT_EQUAL_STRING("ct1 result 1", silly_string_get_caps(root, "CAPSTEST_1"));
    TEST_ASSERT_EQUAL_STRING("ct2 result 2", silly_string_get_caps(root, "CAPsTeSt_2"));

    TEST_ASSERT_NULL(silly_string_get_caps(root, "apple"));
}
    

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(sillyStringGet_should_getCaseSensitiveKeyValues);
    RUN_TEST(sillyStringGetCaseInsensitive_should_getCaseInsensitiveKeyValues);
    RUN_TEST(sillyStringGetCaps_should_getCaseInsensitiveKeyValuesFromCapsInsertion);
    return UNITY_END();
}

