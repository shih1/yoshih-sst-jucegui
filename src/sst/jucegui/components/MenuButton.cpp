/*
 * sst-juce-gui - an open source library of juce widgets
 * built by Surge Synth Team.
 *
 * Copyright 2023-2024, various authors, as described in the GitHub
 * transaction log.
 *
 * sst-basic-blocks is released under the MIT license, as described
 * by "LICENSE.md" in this repository. This means you may use this
 * in commercial software if you are a JUCE Licensee. If you use JUCE
 * in the open source / GPL3 context, your combined work must be
 * released under GPL3.
 *
 * All source in sst-juce-gui available at
 * https://github.com/surge-synthesizer/sst-juce-gui
 */

#include "sst/jucegui/components/MenuButton.h"

namespace sst::jucegui::components
{
MenuButton::MenuButton() : style::StyleConsumer(Styles::styleClass) {}

MenuButton::~MenuButton() {}

void MenuButton::paint(juce::Graphics &g)
{
    float rectCorner = 1.5;

    auto b = getLocalBounds().reduced(1).toFloat();

    auto ol = getColour(Styles::brightoutline);
    auto tx = getColour(Styles::labelcolor);
    auto ar = tx;
    if (isHovered)
    {
        tx = getColour(Styles::labelcolor_hover);
        ar = getColour(Styles::menuarrow_hover);
    }

    g.setColour(ol);
    g.drawRoundedRectangle(b, rectCorner, 1);

    g.setFont(getFont(Styles::labelfont));
    g.setColour(tx);
    g.drawText(label, b.withTrimmedLeft(2), juce::Justification::centredLeft);

    g.setColour(ar);
    auto q = b.withTrimmedRight(2);
    q = q.withLeft(q.getRight() - 10);
    auto cy = q.getCentreY();
    auto au = cy - 2;
    auto ad = cy + 2;

    auto cx = q.getCentreX();
    auto aL = cx - 3;
    auto aR = cx + 3;
    auto p = juce::Path();
    p.startNewSubPath(aL, au);
    p.lineTo(aR, au);
    p.lineTo(cx, ad);
    p.closeSubPath();

    g.fillPath(p);
}
} // namespace sst::jucegui::components