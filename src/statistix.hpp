#pragma once

#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

namespace NsStatistix {
template <typename T> class Stat; // pre-declare the template class itself
template <typename T>
std::ostream &operator<<(std::ostream &o, const Stat<T> &x);

template <typename T> class Stat {
private:
  std::unordered_multimap<std::string, T> mSamples_;
  std::string name_;
  std::string defaultType_;
  size_t numTypes_;
  std::vector<std::string> vTypes_;
  size_t currNumTypes_;

public:
  Stat(std::string name, std::string defaultType, size_t numTypes)
      : name_(name), defaultType_(defaultType), numTypes_(numTypes),
        currNumTypes_(0u) {
    assert(numTypes_ > 0u);
    vTypes_.resize(numTypes_);
    vTypes_[numTypes_ - 1] = defaultType_;
  }

  virtual ~Stat() = default;

  void addSample(T sample) {
    mSamples_.insert(std::make_pair(defaultType_, sample));
  }

  void addSample(T sample, std::string type) {
    auto found = std::find(vTypes_.begin(), vTypes_.end(), type);

    if (found == vTypes_.end()) {
      assert(currNumTypes_ < numTypes_);
      vTypes_[currNumTypes_++] = type;
    }

    mSamples_.insert(std::make_pair(type, sample));
  }

  auto name() const { return name_; }

  auto types() const { return vTypes_; }
  auto type(uint64_t id) const { return vTypes_[id]; }

  auto uniqueTypes() const { return currNumTypes_; }
  auto sampleCount() const { return mSamples_.size(); }
  auto sampleCount(std::string type) const { return mSamples_.count(type); }

  friend std::ostream &operator<<<>(std::ostream &, const Stat<T> &);
};

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Stat<T> &stat) {
  os << stat.name() << " statistics: ";
  os << "Count[All]-" << stat.sampleCount() << " ";
  if (stat.uniqueTypes() > 0u)
    for (uint64_t typeId = 0u; typeId <= stat.uniqueTypes(); ++typeId) {
      os << "Count[" << stat.type(typeId) << "]-"
         << stat.sampleCount(stat.type(typeId)) << " ";
    }

  return os;
}

} // namespace NsStatistix