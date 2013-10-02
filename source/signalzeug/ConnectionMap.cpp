#include <ConnectionMap.h>

namespace signalzeug {

ConnectionMap::ConnectionMap()
{
}

ConnectionMap::~ConnectionMap()
{
	for (std::pair<void*, Connection> pair: _connections)
	{
		pair.second.disconnect();
	}
}

Connection& ConnectionMap::get(void* ptr)
{
	return _connections[ptr];
}

} // namespace signalzeug
