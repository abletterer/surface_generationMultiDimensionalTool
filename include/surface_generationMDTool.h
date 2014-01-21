#ifndef _SURFACE_GENERATIONMDTOOL_PLUGIN_H_
#define _SURFACE_GENERATIONMDTOOL_PLUGIN_H_

#include "plugin_interaction.h"

#include "surface_generationMDTool_dockTab.h"

#include "Geometry/bounding_box.h"

#include "Topology/generic/traversor2.h"

#include "Utils/Shaders/shaderColorPerVertex.h"

#include "Algo/Modelisation/voxellisation.h"

#include "coordinates.h"

#include "vCage.h"

namespace CGoGN
{

namespace SCHNApps
{

class Surface_GenerationMDTool_Plugin : public PluginInteraction
{
	Q_OBJECT
	Q_INTERFACES(CGoGN::SCHNApps::Plugin)

    friend class Surface_GenerationMDTool_DockTab;

public:
    Surface_GenerationMDTool_Plugin()
	{}

    ~Surface_GenerationMDTool_Plugin()
	{}

	virtual bool enable();
	virtual void disable();

    virtual void draw(View* view) {}
    virtual void drawMap(View* view, MapHandlerGen* map);

    virtual void keyPress(View* view, QKeyEvent* event) {}
    virtual void keyRelease(View* view, QKeyEvent* event) {}
    virtual void mousePress(View* view, QMouseEvent* event) {}
    virtual void mouseRelease(View* view, QMouseEvent* event) {}
    virtual void mouseMove(View* view, QMouseEvent* event) {}
    virtual void wheelEvent(View* view, QWheelEvent* event) {}

    virtual void viewLinked(View* view) {}
    virtual void viewUnlinked(View* view) {}

private :
    bool isInCage(PFP2::VEC3 point, std::vector<Dart> cage);

    void createCages(PFP2::MAP* object);
    void markCages(PFP2::MAP* cage, PFP2::MAP* object);

private slots:

    void selectedMapChanged(MapHandlerGen *prev, MapHandlerGen *cur);

public slots:
    //Slots for Python calls
    void initializeCages(const QString& view, const QString& map);

protected:
    Surface_GenerationMDTool_DockTab* m_dockTab;
    std::vector<std::vector<Dart> > m_cages;

    CGoGN::Utils::ShaderColorPerVertex* m_colorPerVertexShader;
    Utils::VBO* m_positionVBO;
    Utils::VBO* m_colorVBO;

    bool m_toDraw;
};

} // namespace SCHNApps

} // namespace CGoGN

#endif

