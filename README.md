MLibs, Copyright Stephen E. MacKenzie, licensed under GPL v2.
C++14 Containers Stevemac::vector – N3797 compliant, no dynamic allocation – Works with STL algorithms

Open Address Hash Table -Double hash, no chaining or probing -Custom std::allocator – Uses the static heap manager – For STL container that takes allocator

C++14 Range-Based Algorithms Predicate and Functor based Work with STL containers -Common functors provided -Resolve via template specialization

C11 Containers -polymorphic types with _Generic factories -Pimpl Idiom – Abstract Data Types – Interface separate from implementation – Opaque Pointers -Custom Static Heap Manager -Work well STL and C algorithms Non-dynamic allocating: -array, binary tree, hashtable, circular linked list, linked list, stack

C11 Algorithms -most of the standard C++ range-based algorithms (STL) in C -Small Footprint -Predicate, Functor Pattern like Qsort and BinSearch in the CRT -Common Functors Provided

Ranged-Based Assembly Algorithms Generic Sort Bytes Transform, Modify Copy Bytes Compare Bytes

C, C++ Test Suite 7000 lines of test code 4200 lines of libraries code Fully automated build, flash, run Embedded and Desktop runs Conformance Tests Library Code not local to projects

Shared with desktop builds Automation Minimal Projects, No IDE Linux, Bash, GNU Makefiles GNU ARM Tools Python Test Harness Texane/STLink Semihosting, floating point printf

To use:

Get arm cross tools https://launchpad.net/gcc-arm-embedded get texane/stlink https://github.com/texane/stlink

Extract STLibs.tar INTO YOUR HOME FOLDER, not under RTOS!

Pull MLibs. Rename the top level folder RTOS. The results should look like this:

STLibs


RTOS

---cinc

---conf

---cppinc

----embtests

----lib

----testsrc

----x86tests