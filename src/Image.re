module Styles = {
  open Css;

  let container =
    style([
      alignItems(center),
      display(flexBox),
      justifyContent(center),
      marginRight(px(12)),
      media("(max-width: 768px)", [marginRight(px(0))]),
    ]);

  let image =
    style([
      border(px(6), solid, rgb(81, 78, 105)),
      borderRadius(`percent(50.0)),
      height(px(256)),
      media("(max-width: 768px)", [height(px(168))]),
    ]);
};

[@react.component]
let make = (~profile: Data.profile) => {
  <section className=Styles.container>
    <img className=Styles.image src={profile.avatar} />
  </section>;
};
