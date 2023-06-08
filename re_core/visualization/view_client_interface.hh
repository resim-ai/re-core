#pragma once

#include "re_core/utils/status.hh"
#include "re_core/visualization/view_update.hh"

namespace re::visualization {

// ViewClient is an abstract interface for objects which communicate with the
// resim View server. It mainly exists to enable mocking in tests for e.g. the
// re::visualization::View object.
class ViewClientInterface {
 public:
  ViewClientInterface() = default;
  ViewClientInterface(const ViewClientInterface &) = delete;
  ViewClientInterface(ViewClientInterface &&) = delete;
  ViewClientInterface &operator=(const ViewClientInterface &) = delete;
  ViewClientInterface &operator=(ViewClientInterface &&) = delete;

  // Send the given update to the server.
  virtual Status send_view_update(const ViewUpdate &update) = 0;

  virtual ~ViewClientInterface() = default;
};

}  // namespace re::visualization
