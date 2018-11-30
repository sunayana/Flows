#include "stdafx.h"
#include "SampleFlowViewReceiver.h"
#include "SampleFlowViewColorsConduit.h"
#include "SampleFlowApp.h"

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;



CRhinoCommand::result CSampleFlowViewReceiver::createSampleFlowView( const CRhinoCommandContext& context, 
    CSampleFlowViewColorsConduit& conduit)
{
    ON_SimpleArray< ON_UUID > viewport_ids;
    ON_SimpleArray< CRhinoView* > view_list;
    CRhinoView* view = nullptr;

    //Build a list of (current) viewport ids
    context.m_doc.GetViewList(view_list, true, false);
    for ( int i = 0; i < view_list.Count(); ++i )
    {
        CRhinoView* view_local = view_list[i];
        if ( view_local )
        {
            viewport_ids.Append(view_local->ActiveViewportID());
        }
    }
    view_list.Empty();

    

    // Create a new view
    context.m_doc.NewView(ON_3dmView(), true);

    // Find the viewport(id) that was just created
    context.m_doc.GetViewList(view_list, true, false);
    for ( int i = 0; i < view_list.Count(); ++i )
    {
        view = view_list[i];
        if ( view )
        {
            const int rc = viewport_ids.Search(view->ActiveViewportID());
            if ( rc < 0 )
                break;
            view = nullptr;
        }
    }

    //Make any necessary updates
    if ( view )
    {
        ON_3dmView v = view->ActiveViewport().View();
        v.m_name = L"Sample Flow View";
        v.m_bShowConstructionGrid = false;

        view->ActiveViewport().SetView(v);
        view->ActiveViewport().SetToPerspectiveView(v.m_name);
        

        const CRhinoDisplayPipeline dp(view->ActiveViewport());
        conduit.Bind(view->ActiveViewport());
        
        
        if (conduit.IsEnabled())
        {
            conduit.Disable();
        }
        else
        {
            conduit.Enable(context.m_doc.RuntimeSerialNumber());
        }
        context.m_doc.Regen();

        view->Redraw();
    }
    else
    {
        return CRhinoCommand::failure;
    }

    return CRhinoCommand::success;
}




CRhinoCommand::result CSampleFlowViewReceiver::action( const CRhinoCommandContext& context,
    CSampleFlowViewColorsConduit& conduit)
{
    
    const auto result = createSampleFlowView(context, conduit);

    return result;
}
