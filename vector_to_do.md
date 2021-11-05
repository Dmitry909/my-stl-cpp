#**Vector's methods to realize**

###**Constructors and destrucor**

+ ~~vector()~~
+ ~~vector(size, T value)~~
+ vector(const vector<T>& other)
+ ~~\~vector()~~

###**Comparison operators**

+ operator==
+ operator!=
+ operator<
+ operator<=
+ operator>
+ operator>=
+ operator<=>

###**Iterators access**

+ const iterator begin() // if object is const
+ iterator begin() // if object isn't const
+ const iterator cbegin()

+ const iterator end()
+ iterator end()
+ const iterator cend()

+ const iterator rbegin()
+ iterator rbegin()
+ const iterator crbegin()

+ const iterator rend()
+ iterator rend()
+ const iterator crend()

###**Modifiers**

+ ~~clear()~~
+ insert()
+ ~~push_back()~~
+ emplace_back()
+ ~~pop_back()~~
+ resize()
+ swap()
+ emplace()
+ erase()

###**Element access**

+ ~~operator[]~~
+ at()
+ front()
+ ~~back()~~
+ data()

###**Memory**

+ ~~empty()~~
+ ~~size()~~
+ max_size() ??? how to realize?
+ ~~capacity()~~
+ reserve()
+ shrink_to_fit()