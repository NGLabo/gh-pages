module Styles = {
  open Css;

  let root =
    style([
      alignItems(center),
      backgroundColor(rgb(64, 61, 88)),
      display(flexBox),
      justifyContent(center),
      minHeight(vh(100.0)),
      padding2(~v=px(0), ~h=px(16)),
    ]);

  let container =
    style([
      display(flexBox),
      justifyContent(center),
      media("(max-width: 768px)", [flexDirection(column)]),
      width(`percent(100.0)),
    ]);
};

[@react.component]
let make = (~profile) => {
  <div className=Styles.root>
    <div className=Styles.container>
      <Image profile />
      <Resume profile />
    </div>
  </div>;
};
