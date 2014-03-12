#ifndef TYPES_H
#define TYPES_h

namespace DL {
	enum DisplayLayer{
		Background = 1,
		Player = 2,
		Foreground = 3,
		GUI
	};
}

namespace ES {
	enum EntityState{
		GoLeft,
		GoRight,
		Stand
	};
}

namespace ET {
	enum EntityType {
		Player,
		Ball
	};
}

#endif // TYPES_H
