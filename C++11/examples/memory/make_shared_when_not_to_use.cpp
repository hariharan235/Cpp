/*
 * Do not *always* use std::make_shared.  This example shows you a
 * situation where using make_shared is not a good idea!
 *
 * References:
 *
 *   [josuttis20190902-05] C++ Smart Pointers - Usage and Secrets
 *     https://youtu.be/XH4xIyS9B2I?t=1115
 *
 *   [mertz20180926] std::make_shared vs. the Normal std::shared_ptr Constructor
 *     https://arne-mertz.de/2018/09/make_shared-vs-the-normal-shared_ptr-constructor/
 */