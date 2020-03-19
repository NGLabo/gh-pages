module Styles = {
  open Css;

  let tag = tag =>
    style([
      backgroundColor(Data.color_of_tag(tag)),
      borderRadius(px(4)),
      color(rgb(55, 53, 47)),
      display(inlineBlock),
      fontSize(rem(0.8)),
      lineHeight(pct(120.0)),
      marginRight(px(4)),
      media("(max-width: 960px)", [marginBottom(px(4))]),
      padding(px(2)),
    ]);
};

[@react.component]
let make = (~tag) => {
  <div className={Styles.tag(tag)}>
    {React.string(Data.string_of_tag(tag))}
  </div>;
};
