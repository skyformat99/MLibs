/*
 * open_map_iterator.h
 *
 *  Created on: May 16, 2015
 *      Author: comet
 */

#ifndef OPEN_MAP_ITERATOR_H_
#define OPEN_MAP_ITERATOR_H_
namespace stevemac {
///===----------------------------------------------------------------------===//
///
/// \class stevemac::iterator
/// \brief Implementation started in fall of 2014. It is is derived from:
/// std::iterator<std::random_access_iterator_tag>.  It has only been tested
/// with stevemac::vector.
///
//===----------------------------------------------------------------------===//
/// Class Template stevemac::iterator
///
//===----------------------------------------------------------------------===//
template <typename Container>
class open_map_iterator : public std::iterator<std::random_access_iterator_tag,
                                             typename Container::value_type> {
public:
  using value_type = typename Container::value_type;
  using pointer = typename Container::pointer;
  using reference = typename Container::reference;
  using difference_type = typename Container::size_type;
  using key_type = typename Container::key_type;
  using mapped_type = typename Container::key_type;

protected:
  /// pointee is owned by the Container
  ///
  pointer pointee;

  //===----------------------------------------------------------------------===//
  /// construct/destroy: The constructor is used for conversion
  /// The pointee member is owned and managed by the Container which is why
  /// iterator does not have any destruction duties
  //===----------------------------------------------------------------------===//

public:
  open_map_iterator() {}
  /// explicit constructor used for converting to the underlying pointer type
  /// provided by the Container: Container::pointer.
  explicit open_map_iterator(pointer ptr) : pointee(ptr) {}

  /// the Container owns the only resource: pointee; hence no duties here.
  ~open_map_iterator() {}
  reference operator*() { return *pointee; }
   pointer operator->() { return pointee; }
   pointer get_ptr() {return pointee;}

   open_map_iterator& operator++() {
	   ++pointee;
       return *this;
     }
     open_map_iterator operator++(int) {
       open_map_iterator tmp = *this;
       ++pointee;
       return tmp;
     }
     ///
     open_map_iterator& operator--() {
    --pointee;
       return *this;
     }
     open_map_iterator operator--(int) {
       open_map_iterator tmp = *this;
        --pointee;
       return tmp;
     }
     difference_type operator-(open_map_iterator& other) {
       return pointee - other.pointee;
     }
     open_map_iterator operator+(difference_type n) {
       return open_map_iterator(pointee + n);
     }
     open_map_iterator operator-(difference_type n) {
       return open_map_iterator(pointee - n);
     }
     open_map_iterator& operator+=(difference_type n) {
       pointee += n;
       return *this;
     }
     open_map_iterator& operator-=(difference_type n) {
       pointee -= n;
       return *this;
     }

     //===----------------------------------------------------------------------===//
     /// logical operators
     ///
     //===----------------------------------------------------------------------===//
     bool operator==(const open_map_iterator &other) const {
       return pointee == other.pointee;
     }

     bool operator!=(const open_map_iterator &other) const {
       return pointee != other.pointee;
     }

     bool operator<(const open_map_iterator &other) {
       return pointee < other.pointee;
     }

     bool operator>(const open_map_iterator &other) {
       return pointee > other.pointee;
     }

     bool operator<=(const open_map_iterator &other) {
       return pointee <= other.pointee;
     }

     bool operator>=(const open_map_iterator &other) {
       return pointee >= other.pointee;
     }

};
} // end namespace



#endif /* OPEN_MAP_ITERATOR_H_ */
