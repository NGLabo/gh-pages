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
          rgba(0, 0, 0, `percent(75.0)),
        ),
      ),
      color(white),
      height(pct(100.0)),
    ]);

  let tableCaption =
    style([
      fontSize(rem(1.4)),
      fontWeight(bold),
      lineHeight(`abs(1.25)),
      letterSpacing(px(1)),
      marginBottom(px(4)),
      marginLeft(px(0)),
      marginRight(px(0)),
      marginTop(px(16)),
      textAlign(center),
    ]);

  let table = style([padding(px(16)), width(pct(100.0))]);

  let tableHeader = style([display(none)]);

  let tableData =
    style([
      borderBottom(px(1), solid, rgb(81, 78, 105)),
      padding(px(2)),
    ]);

  let dataAbsolute = merge([tableData, style([width(px(212))])]);
};

let rs = React.string;

module Item = {
  [@react.component]
  let make = (~attr: Data.attr) => {
    <tr>
      <td className=Styles.dataAbsolute> {attr.name |> rs} </td>
      <td className=Styles.tableData>
        {List.mapi(
           (key, tag) => <Tag key={key |> string_of_int} tag />,
           attr.tags,
         )
         |> Array.of_list
         |> ReasonReact.array}
      </td>
    </tr>;
  };
};

[@react.component]
let make = (~skill: Data.skill) => {
  <div className=Styles.container>
    <header>
      <h3 className=Styles.tableCaption> {skill.name |> rs} </h3>
    </header>
    <table className=Styles.table>
      <thead>
        <tr>
          <th className=Styles.tableHeader> {"Name" |> rs} </th>
          <th className=Styles.tableHeader> {"Tags" |> rs} </th>
        </tr>
      </thead>
      <tbody>
        {List.mapi(
           (key, attr) => {<Item key={key |> string_of_int} attr />},
           skill.attribs,
         )
         |> Array.of_list
         |> ReasonReact.array}
      </tbody>
    </table>
  </div>;
};
