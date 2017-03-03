// ScalingSystem.cpp

#include <Core/ScalingSystem.h>

namespace QCT {
    namespace Core {

        ScalingSystem::ScalingSystem(QObject *_parent) :
            QObject(_parent),
            m_scaleMinimum(0.5),
            m_scaleMaximum(2.5),
            m_scale(1.0) {

        }

        ScalingSystem::~ScalingSystem() {

        }

        ScalingSystem &ScalingSystem::instance() {
            static ScalingSystem helpSystem;
            return helpSystem;
        }

        void ScalingSystem::setScale(const float _scale, const bool _override) {
            const float scaleOld = m_scale;
            if(_scale < m_scaleMinimum && !_override) {
                m_scale = m_scaleMinimum;
            }
            else if(_scale > m_scaleMaximum && !_override) {
                m_scale = m_scaleMaximum;
            }
            else {
                m_scale = _scale;
            }
            if(m_scale != scaleOld) {
                emit signalChangedScale();
            }
        }

    }
}
