//
// Created by xMellox on 05-Aug-20.
//
#include <gtest/gtest.h>
#include <own_type_traits.h>

TEST(CheckTypeTraits,IsString)
{
    int value = 10;
    std::string s{"hey"};

    bool is_value_string = is_string_v<decltype(value)>;
    bool is_s_string = is_string_v<decltype(s)>;

    ASSERT_EQ(is_value_string, false);
    ASSERT_EQ(is_s_string, true);
}

TEST(CheckTypeTraits,IsContainer)
{
    int value = 10;
    std::string s{"hey"};
    std::vector<int> v;
    std::list<int> l;

    bool is_value_container = is_container_v<decltype(value)>;
    bool is_s_container = is_container_v<decltype(s)>;
    bool is_vec_container = is_container_v<decltype(v)>;
    bool is_list_container = is_container_v<decltype(v)>;

    ASSERT_EQ(is_value_container, false);
    ASSERT_EQ(is_s_container, false);
    ASSERT_EQ(is_vec_container, true);
    ASSERT_EQ(is_list_container, true);
}

TEST(CheckTypeTraits,IsTuple)
{
    int value = 10;
    std::string s{"hey"};
    std::vector<int> v;
    std::list<int> l;
    std::tuple<int,int,char> t;
    std::tuple<int,int> t_1;

    bool is_value_tuple = is_tuple_v<decltype(value)>;
    bool is_s_tuple = is_tuple_v<decltype(s)>;
    bool is_vec_tuple = is_tuple_v<decltype(v)>;
    bool is_list_tuple = is_tuple_v<decltype(v)>;
    bool is_t_tuple = is_tuple_v<decltype(t)>;
    bool is_t_1_tuple = is_tuple_v<decltype(t_1)>;

    ASSERT_EQ(is_value_tuple, false);
    ASSERT_EQ(is_s_tuple, false);
    ASSERT_EQ(is_vec_tuple, false);
    ASSERT_EQ(is_list_tuple, false);
    ASSERT_EQ(is_t_tuple, true);
    ASSERT_EQ(is_t_1_tuple, true);
}

TEST(CheckTypeTraits,AreParamsEqual)
{

    bool all_params_equal_1 = are_template_params_equal_v<int,int,int,int,int>;
    bool all_params_equal_2 = are_template_params_equal_v<int,int,short,short,int>;
    bool all_params_equal_3 = are_template_params_equal_v<int,std::string,std::vector<int>,std::stringstream>;

    ASSERT_EQ(all_params_equal_1, true);
    ASSERT_EQ(all_params_equal_2, false);
    ASSERT_EQ(all_params_equal_3, false);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}