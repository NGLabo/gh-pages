module Styles = {
  open Css;

  let section =
    style([color(white), display(flexBox), flexDirection(column)]);

  let details = style([fontSize(rem(0.8)), marginTop(px(8))]);

  let paragraph = style([margin2(~v=px(8), ~h=px(0))]);

  let link = style([color(white), marginRight(px(24))]);

  let icon = style([marginTop(px(32))]);
};

[@react.component]
let make = (~profile: Data.profile) => {
  let age =
    ReasonDateFns.DateFns.differenceInYears(
      Js.Date.fromString(profile.birth),
      Js.Date.make(),
    );

  <section className=Styles.section>
    <Title bg={Css.rgb(193, 69, 102)}> {React.string(profile.name)} </Title>
    <Caption>
      {React.string(profile.role ++ " ")}
      <span ariaLabel="Hot Beverage Emoji" role="img">
        {React.string({js|☕|js})}
      </span>
      <span ariaLabel="Hammer and Wrench Emoji" role="img">
        {React.string({js|🛠|js})}
      </span>
    </Caption>
    <div className=Styles.details>
      <p className=Styles.paragraph>
        {React.string("Age: " ++ Js.Float.toString(age) ++ " ")}
        <span ariaLabel="Sparkles Emoji" role="img">
          {React.string({js|✨|js})}
        </span>
      </p>
      <p className=Styles.paragraph>
        {React.string("Email: ")}
        <a
          className=Styles.link
          href={"mailto:" ++ profile.email ++ "?Subject=Whats%20up!"}
          target="_top">
          {React.string(profile.email)}
        </a>
      </p>
      <p className=Styles.paragraph>
        {React.string("Location: ")}
        <span> {React.string(profile.location)} </span>
      </p>
      <p className=Styles.paragraph>
        {React.string("Personality: ")}
        <span> {React.string(profile.personality)} </span>
      </p>
    </div>
    <div className=Styles.icon>
      <a
        className=Styles.link
        href={profile.social.discord}
        rel="noopener noreferrer"
        target="_blank">
        <Discord />
      </a>
      <a
        className=Styles.link
        href={profile.social.github}
        rel="noopener noreferrer"
        target="_blank">
        <GitHub />
      </a>
      <a
        className=Styles.link
        href={profile.social.linkedin}
        rel="noopener noreferrer"
        target="_blank">
        <Linkedin />
      </a>
    </div>
  </section>;
};
