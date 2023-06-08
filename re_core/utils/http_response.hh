#pragma once

namespace re {

enum class HttpResponse {
  INVALID = -1,
  OK = 200,
  CREATED = 201,
  UNAUTHORIZED = 401,
  FORBIDDEN = 403,
  NOT_FOUND = 404,
};

}  // namespace re
