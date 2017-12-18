#pragma once

#include "../IPostFilter.hpp"

namespace Flounder
{
	class FilterBlurHorizontal :
		public IPostFilter
	{
	private:
		int m_widthValue;
		float m_scaleValue;
		bool m_fitToDisplay;
		float m_sizeScalar;
	public:
		FilterBlurHorizontal(const int &subpass, const float &sizeScalar);

		FilterBlurHorizontal(const int &subpass, const int &width, const int &height);

		~FilterBlurHorizontal();

		void RenderFilter(const VkCommandBuffer &commandBuffer) override;

		float GetScaleValue() const { return m_scaleValue; }

		void SetScaleValue(const float &scaleValue) { m_scaleValue = scaleValue; }
	};
}
