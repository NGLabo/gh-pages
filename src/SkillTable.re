module Styles = {
  open Css;

  let container =
    style([
      backgroundColor(rgb(64, 61, 88)),
      borderRadius(px(16)),
      boxShadow(
        Shadow.box(
          ~x=px(10),
          ~y=px(10),
          ~blur=px(16),
          ~spread=px(-16),
          ~inset=false,
          rgba(0, 0, 0, 0.75),
        ),
      ),
      color(white),
      height(pct(100.0)),
    ]);

  let tcaption =
    style([
      fontSize(rem(1.4)),
      fontWeight(bold),
      unsafe("line-height", "1.25"),
      letterSpacing(px(1)),
      marginBottom(px(4)),
      marginLeft(px(0)),
      marginRight(px(0)),
      marginTop(px(16)),
      textAlign(center),
    ]);

  let t = style([padding(px(16)), width(pct(100.0))]);

  let theader = style([display(none)]);

  let tdata =
    style([
      borderBottom(px(1), solid, rgb(81, 78, 105)),
      padding(px(2)),
    ]);

  let tfixed = merge([tdata, style([width(px(212))])]);
};

[@react.component]
let make = (~skill: Data.skill) => {
  <div className=Styles.container>
    <header>
      <h3 className=Styles.tcaption> {React.string(skill.name)} </h3>
    </header>
    <table className=Styles.t>
      <thead>
        <tr>
          <th className=Styles.theader> {React.string("Name")} </th>
          <th className=Styles.theader> {React.string("Tags")} </th>
        </tr>
      </thead>
      <tbody>
        {ReasonReact.array(
           Array.of_list(
             List.map(
               (attr: Data.attr) => {
                 <tr>
                   <td className=Styles.tfixed>
                     {React.string(attr.name)}
                   </td>
                   <td className=Styles.tdata>
                     {ReasonReact.array(
                        Array.of_list(
                          List.map(tag => <Tag tag />, attr.tags),
                        ),
                      )}
                   </td>
                 </tr>
               },
               skill.attribs,
             ),
           ),
         )}
      </tbody>
    </table>
  </div>;
};
