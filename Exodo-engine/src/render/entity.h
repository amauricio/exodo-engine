#pragma once
#pragma once
#ifndef ENTITY_H
#define ENTITY_H
namespace ExodoEngine {
	namespace render {
		class Entity {
		public:
			Entity(){}
			inline Entity create() {
				Entity g;
				g.isCreated = true;
				return g;
			};
		private:
			void draw();
			static bool isCreated;
			
		};
	}
}
#endif