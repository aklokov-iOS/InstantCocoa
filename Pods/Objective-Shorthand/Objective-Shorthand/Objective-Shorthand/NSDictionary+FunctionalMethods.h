//
//  NSDictionary+FunctionalMethods.h
//  Objective-Shorthand
//
//  Created by Soroush Khanlou on 12/17/13.
//  Copyright (c) 2013 Soroush Khanlou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (FunctionalMethods)

/**
 *  Returns a new dictionary with only the key-value pairs that return `YES` to the `test` block. This function corresponds to `select` or `filter` in other programming languages.
 *
 *  @param test A block that returns a BOOL that determines whether a given key-value pair should be included in the result dictionary. The block takes a parameters `key` and `value` and is called on each element in the dictionary.
 *
 *  @return A new dictionary with only the key-value pairs passing the test.
 */
- (NSDictionary*) dictionaryBySelectingKeysAndValuesPassingTest:(BOOL (^)(id key, id value))test;

/**
 *  Returns a new dictionary with the key-value pairs that return `YES` to the `test` block removed. This function corresponds to `reject` in other programming languages.
 *
 *  @param test A block that returns a BOOL that determines whether a given key-value pair should be removed from the result dictionary. The block takes a parameters `key` and `value` and is called on each element in the dictionary.
 *
 *  @return A new dictionary with only the key-value pairs failing the test.
 */
- (NSDictionary*) dictionaryByRejectingKeysAndValuesPassingTest:(BOOL (^)(id key, id value))test;


/**
 *  Returns a the first key-value pair that returns `YES` to the `test` block. This function corresponds to `match` in other programming languages.
 *
 *  @param test A block that returns a BOOL that determines whether a given key-value pair should be returned. The block takes a parameters `key` and `value` and is called on each element in the dictionary.
 *
 *  @return The first key-value pair found in the dictionary passing the test.
 */
- (id) keyForFirstValuePassingTest:(BOOL (^)(id key, id value))test;

/**
 *  Returns a random key in the dictionary. The random index is generated by arc4random(). This function corresponds to `sample` in other programming languages.
 *
 *  @return A random key in the dictionary.
 */
- (id) randomKey;

/**
 *  Returns a new dictionary with the key-value pairs that are returned by the block parameter. This function corresponds to `map` or `collect` in other programming languages.
 *
 *  @param block A block that returns a new key-value pair to be included in the new dictionary. The block takes a parameters `key` and `value` and is called on each element in the dictionary.
 *
 *  @return A new dictionary with only the key-value pairs failing the test.
 */
- (NSDictionary*) dictionaryByTransformingValuesUsingBlock:(id (^)(id key, id value))block;

/**
 *  Returns an `accumulator` object after it has been called against every key-value pair in the dictionary. This function corresponds to `reduce` or `inject` in other programming languages.
 *
 *  @param block A block that returns the `accumulator` after the key-value pair has been incorporated into the accumulator. The block takes a parameters `accumulator` and `key` and `value` and is called on each element in the dictionary.
 *
 *  @return The accumulator after all key-value pairs have bene incorporated into it.
 */
- (id) objectByReducingKeysAndValuesIntoAccumulator:(id)accumulator usingBlock:(id (^)(id accumulator, id key, id value))block;



/**
 *  Returns `YES` if all key-value pairs in the dictionary return `YES` to the `test` block. This function corresponds to `all` in other programming languages. If any key-value pairs fail the test, the enumeration is short-circuited and ends early.
 *
 *  @param test A block that returns a BOOL that determines if the key-value pair passes the test. The block takes a parameters `key` and `value` and is called on each element in the dictionary.
 *
 *  @return `YES` if all key-value pairs in the dictionary pass the test, otherwise `NO`
 */
- (BOOL) allKeyValuePairsPassTest:(BOOL (^)(id key, id value))test;

/**
 *  Returns `YES` if any of the key-value pairs in the dictionary return `YES` to the `test` block. This function corresponds to `any` in other programming languages. If any key-value pairs passes the test, the enumeration is short-circuited and ends early.
 *
 *  @param test A block that returns a BOOL that determines if the key-value pair passes the test. The block takes a parameters `key` and `value` and is called on each element in the dictionary.
 *
 *  @return `YES` if any one key-value pair in the dictionary passes the test, otherwise `NO`
 */
- (BOOL) anyKeyValuePairsPassTest:(BOOL (^)(id key, id value))test;

/**
 *  Returns `YES` if no key-value pairs in the dictionary return `YES` to the `test` block. This function corresponds to `none` in other programming languages. If any key-value pair passes the test, the enumeration is short-circuited and ends early.
 *
 *  @param test A block that returns a BOOL that determines if the key-value pair passes the test. The block takes a parameters `key` and `value` and is called on each element in the dictionary.
 *
 *  @return `YES` if no key-value pairs in the dictionary pass the test, otherwise `NO`
 */
- (BOOL) noKeyValuePairsPassTest:(BOOL (^)(id key, id value))test;

@end
