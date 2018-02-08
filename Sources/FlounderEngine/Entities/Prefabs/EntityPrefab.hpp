#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "../../Helpers/FormatString.hpp"
#include "../../Resources/Resources.hpp"
#include "../../Files/Csv/FileCsv.hpp"
#include "ComponentPrefab.hpp"

namespace Flounder
{
	class Entity;

	/// <summary>
	/// Class that represents a entity prefab.
	/// </summary>
	class EntityPrefab :
		public IResource
	{
	private:
		std::string m_filename;
		FileCsv *m_fileCsv;
		std::unordered_map<std::string, ComponentPrefab*> *m_components;
	public:
		static EntityPrefab *Resource(const std::string &filename)
		{
			IResource *resource = Resources::Get()->Get(filename);

			if (resource != nullptr)
			{
				return dynamic_cast<EntityPrefab *>(resource);
			}

			EntityPrefab *result = new EntityPrefab(filename);
			Resources::Get()->Add(dynamic_cast<IResource *>(result));
			return result;
		}

		/// <summary>
		/// Creates a new entity prefab.
		/// </summary>
		/// <param name="filename"> The file name. </param>
		EntityPrefab(const std::string &filename);

		~EntityPrefab();

		void Write(Entity *entity);

		void Save();

		std::string GetFilename() override { return m_filename; }

		std::vector<std::string> GetComponents();

		ComponentPrefab *GetComponentData(const std::string &component);
	};
}