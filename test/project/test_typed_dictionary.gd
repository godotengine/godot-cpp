extends RefCounted

func test_typed_dictionary(test, example: Example):
	test.assert_equal(example.test_tdictionary(), { Vector2(1, 2): Vector2i(2, 3) })
	var dictionary: Dictionary[String, int] = { "1": 1, "2": 2, "3": 3 }
	test.assert_equal(example.test_tdictionary_arg(dictionary), 6)
