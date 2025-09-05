#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

// Push Back O(1)
void ULListStr::push_back(const std::string& val){
  
  if(empty()){
    size_ = 0;
    head_ = new Item;
    tail_ = head_;

    tail_->val[tail_->first] = val;
    size_++;
    tail_->last++;
  }
  else{
    if(tail_->last == ARRSIZE){
      tail_->next = new Item;
      tail_->next->prev = tail_;
      tail_ = tail_->next;
      tail_->val[tail_->first] = val;
      size_++;
      tail_->last++;

    }
    else{
      tail_->val[tail_->last] = val;
      size_++;
      tail_->last++;
    }
  }
}

// Pop Back O(1)
void ULListStr::pop_back(){
  if(empty()){
    return;
  }
  else if(tail_->first+1 == tail_->last){
    if(head_ != tail_){
      // Multiple Items (>=2), One val in tail_
      tail_ = tail_->prev;
      delete tail_->next;
      tail_->next = NULL;
      size_--;
    }
    else{
      // One Item, One val
      delete tail_;
      head_ = NULL;
      tail_ = NULL;
      size_ = 0;
    }
  }
  else{
    tail_->val[tail_->last-1] = "";
    tail_->last--;
    size_--;
  }
}

// Push front O(1)
void ULListStr::push_front(const std::string& val){
  if(empty()){
    head_ = new Item;
    tail_ = head_;

    head_->val[head_->first] = val;
    head_->last++;
    size_++;
  }
  else if(head_->first == 0){
    Item* temp = new Item;
    head_->prev = temp;
    temp->next = head_;
    head_ = temp;

    temp->first = ARRSIZE-1;
    temp->last = ARRSIZE;
    temp->val[temp->first] = val;
    size_++;
  }
  else{
    head_->first--;
    head_->val[head_->first] = val;
    size_++;
  }
}

// Pop front O(1)
void ULListStr::pop_front(){
  if(empty()){
    return;
  }
  else if(head_->first+1 == head_->last){
    if(head_ != tail_){
      head_ = head_->next;
      delete head_->prev;
      head_->prev = NULL;
      size_--;
    }
    else{
      delete head_;
      head_ = NULL;
      tail_ = NULL;
      size_ = 0;
    }
  }
  else{
    head_->val[head_->first] = "";
    head_->first++;
    size_--;
  }
}

// const reference to the back element O(1)
std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

// const reference to the front element O(1)
std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

// Returns a pointer to the item at index, loc, O(n)
std::string* ULListStr::getValAtLoc(size_t loc) const{
  // Check if loc is valid
  if(empty()){
    return NULL;
  }
  if(loc >= 0 && loc < size_){
    size_t diff = head_->last - head_->first;
    if(loc < diff){
      // In the head Item
      return &head_->val[head_->first+loc];
    }
    else{
      size_t round = (loc-diff)/ARRSIZE;
      size_t residual =  (loc-diff)%ARRSIZE;
      Item* temp = head_->next;
      for(size_t i = 0; i < round; i++){
        temp = temp->next;
      }
      return &temp->val[temp->first+residual];
    }
  }
  else{
    return NULL;
  }
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
